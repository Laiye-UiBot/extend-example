using System;
using System.Collections.Generic;
using System.Diagnostics;
namespace UiBotPlugin
{
    public interface Plugin_Interface
    {
        int Add(int number1, int number2);
        string GetString();
        void Print();
    }

    public class Plugin_Implement : Plugin_Interface
    {
        public int Add(int number1, int number2)
        {
            return number1 + number2;
        }

        public string GetString()
        {   //可以直接调用UiBot.API.GetString，这是UiBot提供的插件API
            return UiBot.API.GetString("Excel/SaveBook");
        }

        public void Print()
        {
            for(int i = 0; i < 10; i++)
            {
                System.Console.WriteLine(UiBot.API.GetCommanderInfo());
                
                System.Threading.Thread.Sleep(1000);
            }
        }
    }
}
