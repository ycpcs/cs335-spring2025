using Newtonsoft.Json.Linq;

string host = "127.0.0.1";
int port = 8775;

SqlmapRequest sqlmapRequest = new SqlmapRequest(host, port);

//
// Create a new task 
//
string response = await sqlmapRequest.GetAsync("/task/new");
var token = JObject.Parse(response);
string? taskId = token.SelectToken("taskid")?.ToString();
Console.WriteLine($"New taskid: {taskId}");

//
// Delete the task 
//
Console.WriteLine($"Deleting task: {taskId}");
response = await sqlmapRequest.GetAsync($"/task/{taskId}/delete");
token = JObject.Parse(response);
string? success = token.SelectToken("success")?.ToString();
Console.WriteLine($"Delete successful: {success}");

/*
var sqlmapapi = new SqlmapApi(sqlmapRequest);
var taskid = await sqlmapapi.NewTaskAsync();
Console.WriteLine($"New taskid: {taskid}");

Dictionary<string, object> options = new Dictionary<string, object>(); //await sqlmapapi.ListOptionsAsync(taskid);
options["url"] = "http://www.seed-server.com/unsafe_home.php?username=alice&Password=noclue";
options["getDbs"] = true;
options["flushSession"] = true;

foreach (var pair in options)
{
    Console.WriteLine($"{pair.Key} : {pair.Value}");
}

await sqlmapapi.StartTaskAsync(taskid, options);
var status = await sqlmapapi.GetScanStatusAsync(taskid);
while (status.Key != "terminated")
{
    Thread.Sleep(new TimeSpan(0, 0, 5));
    status = await sqlmapapi.GetScanStatusAsync(taskid);
}

List<SqlmapLog> logs = await sqlmapapi.GetLogAsync(taskid);
foreach (SqlmapLog log in logs)
{
    Console.WriteLine($"{log.Time}:{log.Level} : {log.Message}");
}

bool success = await sqlmapapi.DeleteTaskAsync(taskid);
Console.WriteLine("Delete successful: " + success);

*/