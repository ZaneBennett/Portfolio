using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Net.Mime.MediaTypeNames;

namespace HW6
{
    public class GasB : PowerTool
    {
        private int _cc;
        private int _horsepower;
        private string _engineType;
        public int cc { get { return _cc; } private set { _cc = value; } }
        public int horsepower { get { return _horsepower; } private set { _horsepower = value; } }
        public string engineType { get { return _engineType; } private set { _engineType = value; } }
        public GasB(int CC, int HP, string Engine) : base("gas", "backpack", 545.50, 700) 
        {
            _cc = CC;
            _horsepower = HP;
            _engineType = Engine;
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
