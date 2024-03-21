using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HW6
{
    public class Engine : GasB
    {
        public Engine() : base(50, 1, "Two-stroke") { }
        public override string GetDescription()
        {
            string description;
            description = ($"The leaf blower that you selected is a {base.make} blower that is {base.type}.\n" +
                $"It costs ${base.price}, and has a CFM rating of {base.CFM}.\n" +
                $"The engine has a capacity of {base.cc}, {base.horsepower} horsepower, and is of a {base.engineType} type.");
            return description;
        }
    }
}
