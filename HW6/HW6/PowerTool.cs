using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HW6
{
    public abstract class PowerTool
    {
      
        private string _type;
        private string _make;
        private double _price;
        private int _CFM;
        public string type { get { return _type; } private set { _type = value; } }
        public double price { get { return _price; } private set { _price = value; } }
        public string make { get { return _make; } private set { _make = value; } }
        public int CFM {  get { return _CFM; } private set { _CFM = value; } }

        public PowerTool(string Type, string Make, double Price, int cfm)
        {
            _type = Type;
            _make = Make;
            _price = Price;
            _CFM = cfm;
        }

        public abstract string GetDescription();

    }
}
