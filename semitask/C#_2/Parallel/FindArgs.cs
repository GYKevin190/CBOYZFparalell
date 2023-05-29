using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Parallel
{
    public delegate void ResultFoundCallback(List<int> result);
    internal class FindArgs
    {
        public int Min { get; set; }
        public int Max { get; set; }
        public int MaxLength { get; set; }
        public ResultFoundCallback ResultFoundCallback { get; set; }
    }
}
