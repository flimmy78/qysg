﻿using System;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Diagnostics;

namespace register_client
{
    class LogHelper
    {
        public static void WriteLog(string path, string msg, StackTrace st)
        {
            string logPath = path + @"log\";
            if (Directory.Exists(logPath))
            {
            }
            else
            {
                DirectoryInfo directoryInfo = new DirectoryInfo(logPath);
                directoryInfo.Create();
            }

            string fileName = System.IO.Path.GetFileName(st.GetFrame(0).GetFileName());

            StreamWriter write = new StreamWriter(logPath + DateTime.Now.ToString("yyyy-MM-dd") + ".txt", true);

            write.WriteLine(DateTime.Now.ToString("yyyy-MM-dd HH:mm:ss\t") + msg + "\tfile:" + fileName + "\tMethod:" + st.GetFrame(0).GetMethod() + "\tLine Number:" + st.GetFrame(0).GetFileLineNumber());
            write.Flush();
            write.Close();
        }
    }
}
