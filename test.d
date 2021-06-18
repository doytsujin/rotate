import std.stdio;
import std.process;
import std.file;
import std.string;
import std.array;
import std.algorithm;

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
		immutable string RED = "\x1b[31m";
		immutable string GREEN = "\x1b[32m";
		immutable string RESET = "\x1b[0m";
		immutable string filen = e.name;

		auto run = execute(["./a", filen]);

		if (run.status != 0)
			writeln(RED, "Compilation failed \n", RESET, run.output, ' ', filen);
		else
			writeln(GREEN, "Success ", RESET, filen);
	}
	writeln("--------------");
}

void main()
{
	if (!exists("a"))
	{
		writeln("please compile the program by running `make`");
		return;
	}
	writeln("1. Syntax");
	writeln("2. Errors");
	writeln("3. Custom file");
	write("choose [1:3]: ");
	string x = readln().strip;
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
			const auto run = execute(["./a", a]);
		}
	}
	else
	{
		writeln("input is : ", x);
		writeln("Error, no such choice");
		return;
	}

}
