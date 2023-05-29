using Parallel;
using System;
using System.Collections.Generic;
using System.Diagnostics;

class Program
{
    static List<List<int>> Results = new();
    static object HandleResultLock = new object();
    static List<Thread> ThreadList = new();
    static int DesiredSolutionCount = 0;
    static CancellationTokenSource CancellationTokenSources = new CancellationTokenSource();



    static void Main(string[] args)
    {
        if (args.Length != 4)
        {
            Console.WriteLine("Error! You need to give 4 int number as input!. (min,max,solution count,thread num)");
            return;
        }

        var min = int.Parse(args[0]);
        var max = int.Parse(args[1]);
        DesiredSolutionCount = int.Parse(args[2]);
        int threadNum = int.Parse(args[3]);
        ThreadList = new List<Thread>();

        Stopwatch stopwatch = new Stopwatch();
        stopwatch.Start();

        FindArgs findArgs = new FindArgs()
        {
            Min = min,
            Max = max,
            MaxLength = 500,
            ResultFoundCallback = HandleResult
        };

        for (int i = 0; i < threadNum; i++)
        {

            ThreadList.Add(new Thread(new ParameterizedThreadStart(WorkOnSolution)));
            ThreadList[i].Start(findArgs);
        }


        for (int i = 0; i < threadNum; i++)
        {
            ThreadList[i].Join();
        }
        stopwatch.Stop();
        double elapsedseconds = stopwatch.Elapsed.TotalSeconds;

        for (int i = 0; i < Results.Count; i++)
        {
            List<int> result = Results[i];
            var resultString = string.Join(',', result.Select(r => r.ToString()));
            Console.WriteLine(i + 1 + " - " + resultString + "\n");
        }

        Console.WriteLine(Results.Count);
        Console.WriteLine("Time: " + elapsedseconds + " seconds");
    }


    static void WorkOnSolution(object arg)
    {
        var findArgs = (FindArgs)arg;
        while (Results.Count < DesiredSolutionCount)
        {
            FindSolution(findArgs);
        }
    }

    static void FindSolution(FindArgs args)
    {
        var minNum = args.Min;
        var maxNum = args.Max;
        var maxResultLength = args.MaxLength;

        List<int> result = new List<int>();

        while (result.Sum() != 21 && !CancellationTokenSources.IsCancellationRequested)
        {
            Random random = new Random();
            result.Add(random.Next(minNum, maxNum));
            if (result.Count > maxResultLength)
            {
                return;
            }
        }

        if (CancellationTokenSources.IsCancellationRequested)
        {
            return;
        }
        args.ResultFoundCallback(result);
    }

    static void HandleResult(List<int> result)
    {
        lock (HandleResultLock)
        {
            if (Results.Count == DesiredSolutionCount)
                return;

            for (int i = 0; i < Results.Count; i++)
            {
                if (Results[i].Count != result.Count)
                    continue;

                for (int j = 0; j < result.Count; j++)
                {
                    if (Results[i][j] != result[j])
                        break;
                    if (j == result.Count - 1)
                        return;
                }
            }

            Results.Add(result);

            Console.WriteLine("State: " + Results.Count + "/" + DesiredSolutionCount + "    |   " + Math.Round((float)Results.Count / (float)DesiredSolutionCount * 100) + "%");



            if (Results.Count == DesiredSolutionCount)
            {
                CancellationTokenSources.Cancel();
                return;
            }
        }
    }

}