using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HW6
{
    public class Battery : Cordless
    {
        public Battery() : base(20, "charger") { }
        public override string GetDescription()
        {
            string description;
            description = ($"The leaf blower that you selected is a {base.make} blower that is {base.type}.\n" +
                $"It costs ${base.price}, and has a CFM rating of {base.CFM}. It is also a {base.cordStatus}" +
                $" blower, with a voltage of {base.voltage}. Included with it is a {base.charger}.");
            return description;
        }
    }
}
