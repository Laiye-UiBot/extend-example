// UiBot������org.json.*������ֱ�ӵ���
import org.json.*;

public class JavaPlugin
{
	protected void CanNotUse()
	{	//protected��private���Եĺ��������ܱ�UiBot���ã������������������е���
		System.out.println("Cannot use this function");
	}
	
	public String GetString()
	{	//����ֱ�ӵ���UiBot.API.GetString������UiBot�ṩ�Ĳ��API
		return UiBot.API.GetString("Excel/SaveBook");
	}
	
	public JSONArray Concat(JSONArray array1, JSONArray array2)
	{	//���Ҫ����򷵻����飬����org.json.JSONArray����
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