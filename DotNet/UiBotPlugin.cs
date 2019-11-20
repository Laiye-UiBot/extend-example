using Newtonsoft.Json.Linq;

//建议把下面的namespace名字改为您的插件名字
namespace UiBotPlugin
{
    public interface Plugin_Interface
    {   //定义一个插件函数时，必须先在这个interface里面声明
        int Add(int number1, int number2);
        string GetString();
        JArray Concat(JArray array1, JArray array2);
    }

    public class Plugin_Implement : Plugin_Interface
    {   //在这里实现插件函数
        public int Add(int number1, int number2)
        {
            return number1 + number2;
        }

        public string GetString()
        {   //可以直接调用UiBot.API.GetString，这是UiBot提供的插件API
            return UiBot.API.GetString("Excel/SaveBook");
        }

        public JArray Concat(JArray array1, JArray array2)
        {   //如果要传入或返回数组，请用Newtonsoft.Json.Linq.JArray类型
            JArray result = new JArray();
            for (int i = 0; i < array1.Count; i++)
            {
                result.Add(array1[i]);
            }
            for (int i = 0; i < array2.Count; i++)
            {
                result.Add(array2[i]);
            }
            return result;
        }
    }
}
