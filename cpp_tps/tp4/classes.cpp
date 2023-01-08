
#include <string>
#include <iostream>
#include <ctime>
#include <vector>
using namespace std;

class File
{
	protected:
		std::string name;
		std::string location;
		std::string permission;
		std::time_t date;

	public:
		File()
		{
			string a;
			cout <<"name of the file\n";
			cin >> a;
			set_name(a);
			location= "/home";//location
			permission = "rw-rw-rw-";//auto
			date = time(0);// auto
		}

		string get_name()
		{
			return name;
		}
	
		void set_name(string a)
		{
			name=a;
		}

		void set_location(string a)
		{
			location=a;
			return;
		}
		string get_location()
		{
			return location;
		}
	

	friend class Shell;
};

class TextFile : public File
{

	public :
		friend class Directory ;
	
};


class ExecFile : public TextFile
{
	bool flag;

};

class Directory : public File
{
	private:
		Directory* parent;
		std::vector <Directory> sub_directories;
		std::vector <TextFile> sub_textFiles;
		std::vector <ExecFile> sub_execFiles;
	
	public:

	Directory* get_parent()
	{
		return parent;
	}
	void set_parent(Directory* X)
	{
		parent=X;

	}
	
	std::vector <Directory> get_sub_dir()
	{
		return sub_directories;
	}
	void set_sub_dir(std::vector <Directory> L)
	{
		sub_directories=L;
	}

	std::vector <TextFile> get_sub_fl()
	{
		return sub_textFiles;
	}
	void set_sub_fl(std::vector <TextFile> L)
	{
		sub_textFiles=L;
	}
	std::vector <ExecFile> get_sub_fex()
	{
		return sub_execFiles;
	}
	void set_sub_fex(std::vector <ExecFile> L)
	{
		sub_execFiles=L;
	}
	friend class File;
	friend Directory mkdir (string nom, Directory* current);

};



class Shell
{
	private:
		Directory ROOTDIR;
		Directory BINDIR;

	public :
	
		Shell()
		{
			set_rootdir_name("home");
			set_bindir_name("bin");
			set_root_dir_loc("/");
		}
		void set_rootdir_name(string a)
		{
			ROOTDIR.set_name(a);
		}
		void set_bindir_name(string a)
		{
			BINDIR.set_name(a);
		}
		void set_root_dir_loc(string a)
		{
			ROOTDIR.set_location(a);
		}


		Directory* get_rootdir()
		{
			return &ROOTDIR;
		}

		Directory* get_bindir()
		{
			return &BINDIR;
		}
	
		friend class Directory;
};




