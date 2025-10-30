using Microsoft.WindowsAzure.Storage.Auth;
using System;
using System.IO;
using System.Runtime.Serialization.Formatters.Binary;
using System.Security.Cryptography;
using System.Text;

namespace SecureApp
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Console App");
            MD5 md5 = MD5.Create();

            string contents = "Super secure data.";
            byte[] contentBytes = UTF8Encoding.UTF8.GetBytes(contents);

            byte[] hash = md5.ComputeHash(contentBytes);

            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < hash.Length; i++)
            {
                sb.Append(hash[i].ToString("X2"));
            }
            
            StorageCredentials creds = new StorageCredentials("CredScan", "TWFuIGlzIGRpc3Rpbmd1aXNoZWQsIG5vdCBvbmx5IGJ5IGhpcyByZWFzb24sIGJ1dCBieSB0aGlzCBvbmx5IGJ==", "MyCreds");

            Console.WriteLine(sb.ToString());
            Console.ReadLine();

            try
            {
                new BinaryFormatter().Deserialize(new MemoryStream());
            }
            catch (Exception e)
            {
                Console.WriteLine(e);
            }
        }
    }
}