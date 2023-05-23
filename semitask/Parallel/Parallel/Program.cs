using System;

class Program

{
    static void Main(string[] args)
    {
        if (args.Length != 2)
        {
            Console.WriteLine("Error! You need to give 2 int number as input!.");
            return;
        }

        int threadNum = int.Parse(args[0]);
        int successNeededInput = int.Parse(args[1]);    
        float[] values = new float[threadNum];

        float realSuccessNeeded = (float)successNeededInput / threadNum;
        int successNeeded = (int)Math.Round(realSuccessNeeded);

        Parallel.For(0, threadNum, i =>
        {
            DateTime start = DateTime.Now;
            int number = successNeeded;
            int j;
            int k;
            int successCount = 0;
            int card;
            int[] cards = new int[12];
            Random random = new Random();

            for (j = 0; successCount < number; j++)
            {
                k = 0;
                for (int l = 0; l < 12; l++)
                {
                    cards[l] = 0;
                }

                while (SumArray(cards) < 21)
                {
                    card = random.Next(2, 11);
                    cards[k] = card;
                    k++;
                    if (SumArray(cards) == 21)
                    {
                        successCount++;
                    }
                }
            }

            TimeSpan duration = DateTime.Now - start;
            values[i] = (float)duration.TotalSeconds;
        });

        for (int i = 0; i < threadNum; i++)
        {
            Console.WriteLine($"The {i + 1}. thread times was: {values[i]}");
        }
    }

    static int SumArray(int[] array)
    {
        int sum = 0;
        for (int i = 0; i < array.Length; i++)
        {
            sum += array[i];
        }
        return sum;
    }
}