using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HW6
{
    public class ElectricB : PowerTool
    {
        private int _AMPS;
        private string? _cordStatus;
        public int AMPS { get { return _AMPS; } private set { _AMPS = value; } }
        public string? cordStatus { get { return _cordStatus; } private set { _cordStatus = value; } }
        public ElectricB(int amps, string status) : base("electric", "backpack", 400, 300) 
        { 
            _AMPS = amps;
            _cordStatus = status;
        }
        public ElectricB(string status) : base("electric", "handheld", 300, 200)
        {
            _cordStatus = status;
        }
        public override string GetDescription()
        {
            string description;
            description = ($"The leaf blower that you selected is a {base.make} blower that is {base.type}.\n" +
                $"It costs ${base.price}, and has a CFM rating of {base.CFM}.");
            return description;
        }
    }
}
