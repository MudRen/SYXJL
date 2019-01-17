// ban.c
// Created by Xiang@XKX
// #include <net/telnet.h>
#define BANNED_SITES "/adm/etc/banned_sites"
void load_sites();
void add(string pattern);
void remove(string pattern); 
int  is_banned(string site);
void print();
string list_sites();
string *Sites;

void create()
{
    seteuid(getuid());
    load_sites();
}

string list_sites()
{
    if (!sizeof(Sites))
        return ("  ����û�б���ֹ�ĵ�ַ!\n");
    return sprintf("\n  ���ڱ���ֹ���뱾MUD��ip��ַ����:\n  %s\n",implode(Sites, "\n  "));
}

void load_sites()
{
	string *tmp, file;
	int loop;
	Sites = ({});
	// reads in the list of the banned sites
	file = read_file(BANNED_SITES);
	if (!file) return;
	tmp = explode(file, "\n");
   	for(loop=0; loop<sizeof(tmp); loop++)
        	if(tmp[loop][0] == '#' || tmp[loop][0] == '\n' || tmp[loop] == "")
           		continue;
        	else Sites += ({ tmp[loop] });
}

int is_banned(string site)
{
	string *line;
	int i;
	line = ({});
	line += ({site});
	for (i = 0; i < sizeof(Sites); i++)
		if (sizeof(regexp(line, Sites[i])) == 1)
			return 1;
	return 0;
}	

void print()
{
    write(list_sites());
}

void add(string site)
{
	Sites += ({site});
	write_file(BANNED_SITES, Sites[sizeof(Sites)-1] + "\n", 0);
    	write ( "\n  ��ֹ��ַ"+site+"��½��MUD!\n" );	
}

void remove(string site)
{
    int i;
    string *line = ({site});
    if (!is_banned(site)){
        write ("\n  �����ַ��δ����ֹ!\n");
        return;
    }
    for (i = 0; i < sizeof(Sites); i++)
        if (sizeof(regexp(line, Sites[i])) == 1)
            Sites -= ({ Sites[i] });
        write_file(BANNED_SITES, implode(Sites, "\n")+"\n", 1);
    write ( "\n  �����ַ"+site+"...OK!\n" );
    write(list_sites());
}