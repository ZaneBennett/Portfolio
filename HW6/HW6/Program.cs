internal class Program
{
    /// <summary>
    /// The following class is the main program, which includes nested switch statements to allow
    /// the user to select between the different types of leaf blowers. After the selection is
    /// made, an instance of the derived class that the user have selected in instantiated,and
    /// the "GetDescription" method is run. After this, the output is displayed to the user.
    /// </summary>
    /// <param name="args"></param>
    private static void Main(string[] args)
    {
        string finalOutput;
        string? choice;
        Console.WriteLine("Hello! Please select from the following menu to determine the type of\n" +
            "leaf blower that you want to buy.\n");
        Console.WriteLine("1 : Gas\n2 : Electric\n");
        choice = Console.ReadLine();
        switch (choice)
        {
            case "1":
                {
                    PowerTool ngine = new Engine();
                    finalOutput = ngine.GetDescription();
                    Console.WriteLine("\n");
                    Console.WriteLine(finalOutput);
                }
                break;
            case "2":
                {
                    Console.WriteLine("\nSelect an option:\n1 : Corded\n2 : Cordless\n");
                    choice = Console.ReadLine();
                    switch (choice)
                    {
                        case "1":
                            {
                                PowerTool cor = new Cord();
                                finalOutput = cor.GetDescription();
                                Console.WriteLine("\n");
                                Console.WriteLine(finalOutput);
                            }
                            break;
                        case "2":
                            {
                                PowerTool bat = new Battery();
                                finalOutput = bat.GetDescription();
                                Console.WriteLine("\n");
                                Console.WriteLine(finalOutput);
                            }
                            break;
                        default:
                            {
                                Console.WriteLine("\nSorry! That is not a valid option. Please restart the program to try again.");
                            }
                            break;
                    }
                }
                break;
            default:
                {
                    Console.WriteLine("\nSorry! That is not a valid option. Please restart the program to try again.");
                }
                break;
        }
    }
    /// <summary>
    /// This is the main abstract class PowerTool, of which all of the later classes are dervied from.
    /// Since it is abstract, it cannot be instantiated on its own, and its "GetDescription" method
    /// must be overridden by later classes.
    /// </summary>
    public abstract class PowerTool
    {

        private string _type;
        private string _make;
        private double _price;
        private int _CFM;
        public string type { get { return _type; } private set { _type = value; } }
        public double price { get { return _price; } private set { _price = value; } }
        public string make { get { return _make; } private set { _make = value; } }
        public int CFM { get { return _CFM; } private set { _CFM = value; } }

        public PowerTool(string Type, string Make, double Price, int cfm)
        {
            _type = Type;
            _make = Make;
            _price = Price;
            _CFM = cfm;
        }

        public abstract string GetDescription();

    }
    /// <summary>
    /// This is the GasB class, which defines several variables present in the PowerTool class,
    /// and also creates several variables for its own derived class, Engine, to define later.
    /// It overrides the PowerTool class's GetDescription method.
    /// </summary>
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
    /// <summary>
    /// This is the ElectricB class, which fulfills almost the same function as the GasB class,
    /// with some exceptions. This class has two differnt constructors; one is if the user selects
    /// the "Corded" option, while the other is for if the user selects the "Cordless" option.
    /// </summary>
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
    /// <summary>
    /// This class is created automatically when the user selects the "gas" option. It defines the
    /// variables declared in GasB, and it overrides the GetDescription method for the final time
    /// before the object is instantiated.
    /// </summary>
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
    /// <summary>
    /// Since Cord has no extra classes necessary to create afterwards, this class serves almost
    /// the same type of purpose as the previously mentioned Engine class.
    /// </summary>
    public class Cord : ElectricB
    {
        public Cord() : base(12, "corded") { }
        public override string GetDescription()
        {
            string description;
            description = ($"The leaf blower that you selected is a {base.make} blower that is {base.type}.\n" +
                $"It costs ${base.price}, and has a CFM rating of {base.CFM}." +
                $"It has {base.AMPS} AMPs of power, and it is {base.cordStatus}.");
            return description;
        }
    }
    /// <summary>
    /// This is the other option that is selctable after the user selects "Electric". This class,
    /// unlike Cord, requires another class afterwards to define some of the variables present here.
    /// </summary>
    public class Cordless : ElectricB
    {
        private int _voltage;
        private string? _charger;
        public int Voltage { get { return _voltage; } private set { _voltage = value; } }
        public string? Charger { get { return _charger; } private set { _charger = value; } }
        public Cordless(int voltage, string charger) : base(8, "cordless")
        {
            _voltage = voltage;
            _charger = charger;
        }

        public override string GetDescription()
        {
            string description;
            description = ($"The leaf blower that you selected is a {base.make} blower that is {base.type}.\n" +
                $"It costs ${base.price}, and has a CFM rating of {base.CFM}. It is a {base.cordStatus} blower.");
            return description;
        }

    }
    /// <summary>
    /// This is the final class in the program, and it is created automatically after the user selects "Cordless".
    /// </summary>
    public class Battery : Cordless
    {
        public Battery() : base(20, "charger") { }
        public override string GetDescription()
        {
            string description;
            description = ($"The leaf blower that you selected is a {base.make} blower that is {base.type}.\n" +
                $"It costs ${base.price}, and has a CFM rating of {base.CFM}. It is also a {base.cordStatus}" +
                $" blower, with a voltage of {base.Voltage}.\n" +
                $"Included with it is a {base.Charger}.");
            return description;
        }
    }

    //I think that this was a really good last assignment, as it really helped me to be able to practice
    //many of the concepts that we were taught in class, and I feel like I understand Object-Oriented 
    //programming all the better because of it. Thank you!
}