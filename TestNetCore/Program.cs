using System;
using System.Security.Cryptography;

namespace TestNetCore
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Hello World!");
        }

        public void Encrypt()
        {
            var md5 = MD5.Create();
            var md5Bytes = new byte[10];
            md5.ComputeHash(md5Bytes);

            var sha1 = SHA1.Create();
            var sha1Bytes = new byte[10];
            sha1.ComputeHash(sha1Bytes);
        }
    }
}
