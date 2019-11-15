// UiBot内置了org.json.*，可以直接导入
import org.json.*;

public class JavaPlugin
{
	protected void CanNotUse()
	{	//protected或private属性的函数，不能被UiBot调用，但可以在其他函数中调用
		System.out.println("Cannot use this function");
	}
	
	public int Add(int number1, int number2)
	{
		return number1 + number2;
	}
	
	public String GetString()
	{	//可以直接调用UiBot.API.GetString，这是UiBot提供的插件API
		return UiBot.API.GetString("Excel/SaveBook");
	}
	
	public JSONArray Concat(JSONArray array1, JSONArray array2)
	{	//如果要传入或返回数组，请用org.json.JSONArray类型
		JSONArray result = new JSONArray();
		for (int i = 0; i < array1.length(); i++) 
		{
				result.put(array1.get(i));
		}
		for (int i = 0; i < array2.length(); i++) 
		{
				result.put(array2.get(i));
		}
		return result;
	}
}