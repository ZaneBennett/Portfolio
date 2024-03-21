using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HW6
{
    public class Cordless : ElectricB
    {
        private int _voltage;
        private string? _charger;
        public int voltage { get { return _voltage; } private set { _voltage = value; } }
        public string? charger { get { return _charger; } private set { _charger = value; } }
        public Cordless(int VOLTAGE, string CHARGER) : base (8, "cordless") 
        {
            int _voltage = VOLTAGE;
            string _charger = CHARGER;
        }

        public override string GetDescription()
        {
            string description;
            description = ($"The leaf blower that you selected is a {base.make} blower that is {base.type}.\n" +
                $"It costs ${base.price}, and has a CFM rating of {base.CFM}. It is a {base.cordStatus} blower.");
            return description;
        }

    }
}
