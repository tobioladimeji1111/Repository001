namespace TestNamespace
{
    using Microsoft.AspNetCore.Mvc;

    public class TestController : Controller
    {
        [HttpPost]
        public ActionResult TransferMoney(string toAccount, string amount)
        {
            // You don't want an attacker to specify to who and how much money to transfer.

            return null;
        }
    }
}
