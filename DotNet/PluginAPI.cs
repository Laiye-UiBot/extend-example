//这个文件一般不需要您修改，请保持以下内容不变

using System;
using System.Runtime.InteropServices;
using System.Text;

namespace UiBot
{
    class RawPtr
    {
        [DllImport("LuaApi.dll", CallingConvention = CallingConvention.Cdecl)]
        internal static extern IntPtr GetString(byte[] lpPath);

        [DllImport("LuaApi.dll", CallingConvention = CallingConvention.Cdecl)]
        internal static extern IntPtr GetCommanderInfo();

        [DllImport("LuaApi.dll", CallingConvention = CallingConvention.Cdecl)]
        internal static extern int ExecuteStatement(byte[] lpStatement);
    }

    public class API
    {
        [DllImport("LuaApi.dll", CallingConvention = CallingConvention.Cdecl)]
        internal static extern bool IsStop();
        
        protected static string PtrToString(IntPtr RawPtr)
        {
            IntPtr p = RawPtr;

            int i = 0;
            while (Marshal.ReadByte(p + i) != 0)
                i++;

            byte[] bytes = new byte[i];

            for (i--; i >= 0; i--)
                bytes[i] = Marshal.ReadByte(p + i);

            return System.Text.Encoding.UTF8.GetString(bytes);
        }

        public static string GetString(string strPath)
        {
            return PtrToString(RawPtr.GetString(Encoding.UTF8.GetBytes(strPath)));
        }

        public static string GetCommanderInfo()
        {
            return PtrToString(RawPtr.GetCommanderInfo());
        }
        
        public static int ExecuteStatement(string strStatement)
        {
            return RawPtr.ExecuteStatement(Encoding.UTF8.GetBytes(strStatement));
        }
    }
}
