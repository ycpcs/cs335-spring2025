using System.Net.Http.Headers;
using System.Text;

public class SqlmapRequest
{
    private string host;
    private int port;
    public SqlmapRequest(string h, int p = 8775)
    {
        host = h;
        port = p;
    }
    public async Task<string> GetAsync(string url)
    {
        using (HttpClient client = new HttpClient())
        {
            HttpResponseMessage response = await client.GetAsync($"http://{host}:{port}{url}");
            response.EnsureSuccessStatusCode();
            string responseContent = await response.Content.ReadAsStringAsync();
            return responseContent;
        }
    }
    public async Task<string> PostAsync(string url, string data)
    {       
        using (HttpClient client = new HttpClient())
        {
            byte[] buffer = Encoding.ASCII.GetBytes(data);
            
            var byteContent = new ByteArrayContent(buffer);
            byteContent.Headers.ContentType = new MediaTypeHeaderValue("application/json");

            HttpResponseMessage response = await client.PostAsync($"http://{host}:{port}{url}", byteContent);
            response.EnsureSuccessStatusCode();
            string responseContent = await response.Content.ReadAsStringAsync();
            return responseContent;
        }
    }
}