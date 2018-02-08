using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace FlyFramework
{
    public class CIniCtrl
    {
        #region API��������

        [System.Runtime.InteropServices.DllImport("kernel32")]//����0��ʾʧ�ܣ���0Ϊ�ɹ�
        private static extern long WritePrivateProfileString(string section, string key,
            string val, string filePath);

        [System.Runtime.InteropServices.DllImport("kernel32")]//����ȡ���ַ����������ĳ���
        private static extern long GetPrivateProfileString(string section, string key,
            string def, StringBuilder retVal, int size, string filePath);


        #endregion

        #region ��Ini�ļ�

        public static string ReadIniData(string Section, string Key, string NoText, string iniFilePath)
        {
            if (File.Exists(iniFilePath))
            {
                StringBuilder temp = new StringBuilder(1024);
                GetPrivateProfileString(Section, Key, NoText, temp, 1024, iniFilePath);
                return temp.ToString();
            }
            else
            {
                return String.Empty;
            }
        }

        #endregion

        #region дIni�ļ�

        public static bool WriteIniData(string Section, string Key, string Value, string iniFilePath)
        {
            if (!File.Exists(iniFilePath))
            {
                File.Create(iniFilePath).Close();
            }

            long OpStation = WritePrivateProfileString(Section, Key, Value, iniFilePath);
            if (OpStation == 0)
            {
                return false;
            }
            else
            {
                return true;
            }
        }

        #endregion
    }
}
