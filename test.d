import std.stdio;
import std.process;
import std.file;
import std.string;
import std.array;
import std.algorithm;

/// display output in red
immutable string RED = "\x1b[31m";
/// display output in green
immutable string GREEN = "\x1b[32m";
/// reset display output color
immutable string RESET = "\x1b[0m";

/// iters thru files and runs them and collects exit status
void iterRunAndCollect(string dir)
{
	if (exists("output.md"))
	{
		auto f = File("output.md", "w");
		f.close();
	}

	foreach (DirEntry e; dirEntries(dir, SpanMode.shallow).filter!(f => f.name.endsWith(".vr")))
	{

		immutable string filen = e.name;

		const auto run = execute(["./rotate", filen]);

		if (run.status != 0)
			writeln(RED, "Compilation failed \n", RESET, run.output);
		else
			writeln(GREEN, "Success ", RESET, filen);
	}
	writeln("--------------");
}

void main()
{
		if (!exists("./rotate"))
	{
    writeln("running make");
	  execute("make");
		writeln("file does not exist");
		return;
	}
	writeln("1. Syntax");
	writeln("2. Errors");
	writeln("3. Custom file");
	write("choose [1:3]: ");
	const string x = readln().strip;
	writeln("--------------");
	if (exists("output.md"))
	{
		auto f = File("output.md", "w");
		f.close();
	}

	if (x == "1")
	{
		"examples/".iterRunAndCollect;
	}
	else if (x == "2")
	{
		"examples/errors/".iterRunAndCollect;
	}
	else if (x == "3")
	{
		write("file name: ");
		string a = readln().strip;
		if (!exists(a))
		{
			writeln("file does not exist");
			return;
		}
		else
		{
			const auto run = execute(["./rotate", a]);
			if (run.status != 0)
			{
				writeln(RED, "Failure");
			}
			else
			{
				writeln(GREEN, "Success");
			}
			write(RESET);
		}
	}
	else
	{
		writeln("input is : ", x);
		writeln("Error, no such choice");
		return;
	}

}
