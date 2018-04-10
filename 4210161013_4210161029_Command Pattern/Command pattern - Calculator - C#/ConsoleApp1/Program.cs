using System;
using System.Collections;
using System.Collections.Generic;

namespace ConsoleApp1
{
    interface Command
    {
        void execute();
        void undo();
    }

    class CommandManager
    {
        Stack<Command> undos = new Stack<Command>();
        Stack<Command> redos = new Stack<Command>();

        public void executeCommand(Command _c)
        {
            _c.execute();
            undos.Push(_c);
            redos.Clear();
        }
        
        public bool isUndoAble()
        {
            if (undos.Count != 0)
            {
                return true;
            }
            return false;
        }

        public void undo()
        {
            if(undos.Count != 0)
            {
                Command c = undos.Pop();
                c.undo();
                redos.Push(c);
            }
        }
        
    }

    class CalculatorModel
    {
        int x;
        int y;
        public int current;
        CommandManager cmdMgr;
        public CalculatorModel()
        {
            x = 0;
            y = 0;
            cmdMgr = new CommandManager();
        }

        public void undo()
        {
            cmdMgr.undo();
        }

        public void redo()
        {
            //cmdMgr
        }

        public void add(int _x)
        {
            cmdMgr.executeCommand(new AddCommand(this, _x));
        }

        public void substract(int _x)
        {
            cmdMgr.executeCommand(new SubstractCommand(this, _x));
        }

        public void divide(int _x)
        {
            cmdMgr.executeCommand(new DivideCommand(this, _x));
        }

        public void multiply(int _x)
        {
            cmdMgr.executeCommand(new MultiplyCommand(this, _x));
        }
    }

    class AddCommand : Command
    {
        CalculatorModel calc;
        int x;
        public AddCommand(CalculatorModel _calc, int _x)
        {
            calc = _calc;
            x = _x;
        }
        public void execute()
        {
            calc.current = calc.current + x;
        }

        public void undo()
        {
            calc.current = calc.current - x;
        }
    }

    class SubstractCommand : Command
    {
        CalculatorModel calc;
        int x;
        public SubstractCommand(CalculatorModel _calc, int _x)
        {
            calc = _calc;
            x = _x;
        }
        public void execute()
        {
            calc.current = calc.current - x;
        }

        public void undo()
        {
            calc.current = calc.current + x;
        }
    }

    class DivideCommand : Command
    {
        CalculatorModel calc;
        int x;
        public DivideCommand(CalculatorModel _calc, int _x)
        {
            calc = _calc;
            x = _x;
        }
        public void execute()
        {
            calc.current = calc.current / x;
        }

        public void undo()
        {
            calc.current = calc.current * x;
        }
    }

    class MultiplyCommand : Command
    {
        CalculatorModel calc;
        int x;
        public MultiplyCommand(CalculatorModel _calc, int _x)
        {
            calc = _calc;
            x = _x;
        }
        public void execute()
        {
            calc.current = calc.current * x;
        }

        public void undo()
        {
            calc.current = calc.current / x;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            CalculatorModel calc = new CalculatorModel();
            int inputOperand = 0;
            string inputOperator = "";
            while(inputOperator != "exit")
            {
                Console.Write("masukkan operator ( +, -, /, * , undo) : ");
                inputOperator = Console.ReadLine();
                if (inputOperator == "undo" || inputOperator == "Undo" || inputOperator == "UNDO")
                {
                    calc.undo();
                    Console.WriteLine("hasil " + calc.current.ToString());
                }
                else
                {
                    Console.Write("masukkan operand : ");
                    inputOperand = int.Parse(Console.ReadLine());
                    switchCommand(calc, inputOperator, inputOperand);
                }
            }
            Console.ReadKey();
        }

        private static void switchCommand(CalculatorModel _calc, string _inputOperator, int _inputOperand)
        {
            switch (_inputOperator)
            {
                case "+":
                    _calc.add(_inputOperand);
                    break;
                case "-":
                    _calc.substract(_inputOperand);
                    break;
                case "/":
                    _calc.divide(_inputOperand);
                    break;
                case "*":
                    _calc.multiply(_inputOperand);
                    break;
            }
            Console.WriteLine("hasil " + _calc.current.ToString());
        }
    }
}
