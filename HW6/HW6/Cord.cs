using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HW6
{
    internal class Cord : ElectricB
    {
        public Cord() : base (12, "corded") { }
        public override string GetDescription()
        {
            string description;
            description = ($"The leaf blower that you selected is a {base.make} blower that is {base.type}.\n" +
                $"It costs ${base.price}, and has a CFM rating of {base.CFM}." +
                $"It has {base.AMPS} AMPs of power, and it is {base.cordStatus}.");
            return description;
        }
    }
}
