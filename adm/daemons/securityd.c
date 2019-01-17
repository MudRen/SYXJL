// securityd.c by aeolus 12/25/2000 ʥ���� xixi :)
#include <login.h>

// By Annihilator@Eastern.Stories (11/25/94)

// This is the "effective" access status compare to the "status" property
// in login object that this mapping determine wizards' access rights
// directly. It is important to make the "status" property matches this
// mapping for wizards higher than regular wizard such as sage, arch and
// admin. For thoese users whose name doesnot appear in this mapping, they
// are divided into three groups (wizard),(player) and (object) using
// wizardp() and interactive() efun.
// The parenthesis is nessessary to prevend players naming themself "admin"
// to hack the security system.
// 
// 01/14/95 Annihilator - wiz_status are defined outside this daemon in the
//                        WIZLIST file.
// Modified by Xiang for XKX

mapping wiz_status;

string *wiz_levels = ({
        "(player)",
        "(immortal)",
        "(apprentice)",
        "(wizard)",
        "(angel)",
        "(arch)",
        "(sage)",
        "(admin)"
});

// A valid write attempt must pass 2 checks: your uid or status must not be
// "excluded" and must be "trusted" on that directory in order to write in 
// that directory. The directories containing the file is searched backward
// from the current directory to root. And exclude is checked prior than
// trusted.

// ���ļ���дȨҪ���������жϣ�
// 1.trusted_write�����õ�euid(Ӣ��id)��status(��ʦ�ȼ�)����дȨ��
mapping trusted_write = ([
        "/":            ({ "Root","(admin)" }),
        "adm":          ({ "(admin)" }),
        "backup":       ({ "(sage)","(admin)" }),
        "binaries":     ({ "(arch)","(sage)","(admin)" }),
        "data":         ({ "(sage)","(admin)" }),
        "dump":         ({ "(sage)","(admin)" }),
        "clone":        ({ "(wizard)","(angel)","(arch)","(sage)","(admin)" }),
        "cmds":         ({ "(sage)","(admin)" }),
        "d":            ({ "(wizard)","(angel)","(arch)","(sage)","(admin)" }),
        "data":         ({ "(sage)","(admin)" }),
        "doc":          ({ "(apprentice)","(wizard)","(angel)","(arch)","(sage)","(admin)" }),
        "feature":      ({ "(arch)","(sage)", "(admin)" }),
        "hate":         ({ "(wizard)","(angel)","(arch)","(sage)","(admin)" }),
        "include":      ({ "(arch)","(sage)","(admin)" }),
        "inherit":      ({ "(arch)","(sage)","(admin)" }),
        "kungfu":       ({ "(wizard)","(angel)","(arch)","(sage)","(admin)" }),
        "log":          ({ "(sage)","(admin)" }),
        "maxim":        ({ "(wizard)","(angel)","(arch)","(sage)","(admin)" }),
        "obj":          ({ "(wizard)","(angel)","(arch)","(sage)","(admin)" }),
        "quest":        ({ "(wizard)","(angel)","(arch)","(sage)","(admin)" }),
        "task":         ({ "(arch)","(sage)","(admin)" }),
        "tmp":          ({ "(arch)","(sage)","(admin)" }),
        "u":            ({ "(arch)","(sage)","(admin)" }),
        "www":          ({ "(arch)","(sage)","(admin)" }),
]);
// 2.exclude_write�����õ�euid(Ӣ��id)��status(��ʦ�ȼ�) �� ����дȨ��
//   exclude_write��trusted_write�������ȼ�����
//   ��exclude_write�����õ�Ȩ�������trusted_write��ͬ��������Ȼ �� ����дȨ��
//   exclude_write�����÷����ɲο�exclude_read��
mapping exclude_write = ([
        "adm/etc":      ({ "(immortal)","(apprentice)","(wizard)","(angel)","(arch)","(sage)" }),
        "adm/daemons":  ({ "(immortal)","(apprentice)","(wizard)","(angel)","(arch)","(sage)" }),
        "adm/daemons/securityd.c": ({ "(immortal)","(apprentice)","(wizard)","(angel)","(arch)","(sage)" }),
        "backup":       ({ "(immortal)","(apprentice)","(wizard)","(angel)","(arch)" }),
        "cmds":         ({ "(immortal)","(apprentice)","(wizard)","(angel)","(arch)" }),
        "cmds/usr":     ({ "(immortal)","(apprentice)","(wizard)","(angel)","(arch)" }),
        "cmds/std":     ({ "(immortal)","(apprentice)","(wizard)","(angel)","(arch)" }),
        "cmds/skill":   ({ "(immortal)","(apprentice)","(wizard)","(angel)","(arch)" }),
        "cmds/app":     ({ "(immortal)","(apprentice)","(wizard)","(angel)","(arch)" }),
        "cmds/wiz":     ({ "(immortal)","(apprentice)","(wizard)","(angel)","(arch)" }),
        "cmds/ang":     ({ "(immortal)","(apprentice)","(wizard)","(angel)","(arch)" }),
        "cmds/arch":    ({ "(immortal)","(apprentice)","(wizard)","(angel)","(arch)" }),
        "cmds/sag":     ({ "(immortal)","(apprentice)","(wizard)","(angel)","(arch)" }),
        "cmds/adm":     ({ "(immortal)","(apprentice)","(wizard)","(angel)","(arch)" }),
        "log":          ({ "(immortal)","(apprentice)","(wizard)","(angel)","(arch)" }),
        "backup":       ({ "(immortal)","(apprentice)","(wizard)","(angel)","(arch)" }),
        "data":         ({ "(immortal)","(apprentice)","(wizard)","(angel)","(arch)" }),
        "dump":         ({ "(immortal)","(apprentice)","(wizard)","(angel)","(arch)" }),
]);

mapping trusted_read = ([
        "adm":          ({ "(sage)","(admin)" }),
        "binaries":     ({ "(wizard)","(arch)","(sage)","(admin)" }),
        "clone":        ({ "(wizard)","(arch)","(sage)","(admin)" }),
        "cmds/adm":     ({ "(admin)" }),
        "cmds/sag":     ({ "(sage)","(admin)" }),
        "cmds/arch":    ({ "(arch)","(sage)","(admin)" }),
        "cmds/ang":     ({ "(angel)","(arch)","(sage)","(admin)" }),
        "cmds/wiz":     ({ "(wizard)","(angel)","(arch)","(sage)","(admin)" }),
        "cmds/app":     ({ "(apprentice)","(wizard)","(angel)","(arch)","(sage)","(admin)" }),
        "d/city/obj/bingqipu.o": ({ 
"(player)","(immortal)","(apprentice)","(wizard)","(angel)","(arch)","(sage)" ,"(admin)" }),
        "backup":       ({ "(arch)","(sage)","(admin)" }),
        "date":         ({ "(arch)","(sage)","(admin)" }),
        "dump":         ({ "(arch)","(sage)","(admin)" }),
        "log":          ({ "(arch)","(sage)","(admin)" }),
        "u/aeolus":     ({ "(admin)" }),
        "u/bsd":        ({ "(admin)" }),
]);

// exclude_read��Ȩ�����òο�exclude_write��ע�͡�
mapping exclude_read = ([
        "adm":          ({ "(immortal)","(apprentice)","(wizard)","(angel)","(arch)" }),
        "adm/daemons/securityd.c": ({ "(immortal)","(apprentice)","(wizard)","(angel)", "(arch)","(sage)" }),
        "backup":       ({ "(immortal)","(apprentice)","(wizard)","(angel)" }),
        "d":            ({ "(immortal)","(apprentice)" }),
        "dump":         ({ "(immortal)","(apprentice)","(wizard)","(angel)" }),
        "u":            ({ "(immortal)","(apprentice)","(wizard)","(angel)" }),
        "u/aeolus":     ({ "(immortal)","(apprentice)","(wizard)","(angel)","(arch)","(sage)" }),
        "u/bsd":        ({ "(immortal)","(apprentice)","(wizard)","(angel)","(arch)","(sage)" }),
        "feature":      ({ "(immortal)","(apprentice)","(wizard)","(angel)" }),
        "task":         ({ "(immortal)","(apprentice)","(wizard)","(angel)" }),
        "topten":       ({ "(immortal)","(apprentice)","(wizard)","(angel)" }),
        "inherit":      ({ "(immortal)","(apprentice)","(wizard)","(angel)" }),
        "www":          ({ "(immortal)","(apprentice)","(wizard)","(angel)" }), 
        "kungfu":       ({ "(immortal)","(apprentice)" }),
        "clone":        ({ "(immortal)","(apprentice)" }),
        "date":         ({ "(immortal)","(apprentice)","(wizard)","(angel)" }),
        "hate":         ({ "(immortal)","(apprentice)" }),
        "quest":        ({ "(immortal)","(apprentice)" }),
        "maxim":        ({ "(immortal)","(apprentice)" }),
        "obj":          ({ "(immortal)","(apprentice)" }),
        "log":          ({ "(immortal)","(apprentice)","(wizard)","(angel)" }),
        "cmds/adm":     ({ "(immortal)","(apprentice)","(wizard)","(angel)","(arch)" }),
        "cmds/sag":     ({ "(immortal)","(apprentice)","(wizard)","(angel)","(arch)" }),
        "cmds/arch":    ({ "(immortal)","(apprentice)","(wizard)","(angel)" }),
        "cmds/ang":     ({ "(immortal)","(apprentice)","(wizard)" }),
        "cmds/wiz":     ({ "(immortal)","(apprentice)" }),
        "doc/wiz":      ({ "(player)" }),
]);

void create()
{
        string *wizlist, wiz_name, wiz_level;
        int i;

        wizlist = explode(read_file(WIZLIST), "\n");
        wiz_status = allocate_mapping(sizeof(wizlist));
        for(i=0; i<sizeof(wizlist); i++) {
                if( wizlist[i][0]=='#' 
                || sscanf(wizlist[i], "%s %s", wiz_name, wiz_level)!=2 ) continue;
                wiz_status[wiz_name] = wiz_level;
        }
}

string *query_wizlist() { return keys(wiz_status); }

// This function returns the status of an uid.
string get_status(mixed ob)
{
        string euid;
        
        if( objectp(ob) ) {
                euid = geteuid(ob);
                if( !euid ) euid = getuid(ob);
        }
        else if( stringp(ob) ) euid = ob;

        if (!mapp(wiz_status)) return "(player)";
        if( !undefinedp(wiz_status[euid]) ) return wiz_status[euid];
        else if( member_array(euid, wiz_levels)!=-1 ) return euid;
        else return "(player)";
}

int get_wiz_level(object ob)
{
        return member_array(get_status(ob), wiz_levels);
}

int set_status(mixed ob, string status)
{
        string uid, *wiz, wizlist;
        int i;

        if( geteuid(previous_object())!= ROOT_UID ) return 0;

        if( userp(ob) ) uid = getuid(ob);
        else if(stringp(ob)) uid = ob;
        else return 0;
        
        if( status == "(player)" )
                map_delete(wiz_status, uid);
        else
                wiz_status[uid] = status;
        wiz = keys(wiz_status);
        for(wizlist = "", i=0; i<sizeof(wiz); i++)
                wizlist += wiz[i] + " " + wiz_status[wiz[i]] + "\n";
        rm(WIZLIST);
        write_file(WIZLIST, wizlist);
        log_file( "static/promotion", capitalize(uid)
                 + " become a " + status + " on " + ctime(time()) + "\n" );
        return 1;
}

string *get_wizlist() { return keys(wiz_status); }

int valid_read(string file, mixed user, string func)
{
        string euid, status, *path, dir;
        int i;
        
        if( !objectp(user) )
                error("TRUST_D->valid_read: Invalid argument type of user.\n");

        // Let user restore their save file
        if( func=="restore_object" ) {
                if( sscanf(file, "/data/%*s") && (
                      ( file == (string) user->query_save_file() )||
                      ( file == (string) user->query_save_file() + ".o" ) ) )
                        return 1;
        }
        
        if (    func != "read_file" &&
                func != "file_size" &&
                func != "stat" &&
                func != "read_bytes" &&
                func != "tail" &&
                func != "ed_start"
        ) return 1;
        
        // Get the euid and status of the user.
        if( !euid = geteuid(user) )
                return 1;
        status = get_status(user);

        if( euid==ROOT_UID ) return 1;

        if( sscanf(file, "/u/" + euid + "/%*s") )
                return 1;

        path = explode(file, "/");

        for(i=sizeof(path)-1; i>=0; i--) {
                dir = implode(path[0..i], "/");
                if( undefinedp(exclude_read[dir]) ) continue;
                if( member_array(euid, exclude_read[dir])!=-1 ) return 0;
                if( member_array(status, exclude_read[dir])!=-1 ) return 0;
        }

        return 1;
}

// valid_write - called by the master object to determine whether if an user
//               is allowed to write on a certain file.
// NOTE:
//     The argument user should be an object according to the source code
// of driver. However, it is a mixed type in the released docs. We assume
// it is an object in normal case here and issue an error if it was not
// an object.                                            - Annihilator

int valid_write(string file, mixed user, string func)
{
        string euid, status, *path, dir;
        int i;

        if( !objectp(user) )
                error("TRUST_D->valid_write: Invalid argument type of user.\n");

        if( sscanf(file, LOG_DIR + "%*s") && func=="write_file" ) return 1;

        // Let user save their save file
        if( func=="save_object" ) {
                if( sscanf(file, "/data/%*s") && (
                      ( file == (string) user->query_save_file() )||
                      ( file == (string) user->query_save_file() + ".o") ) )
                        return 1;
        }

        // Get the euid and status of the user.
        if( !euid = geteuid(user) )
                return 0;
        status = get_status(user);

        if( euid==ROOT_UID ) return 1;

        if( sscanf(file, "/u/" + euid + "/%*s") )
                return 1;

        path = explode(file, "/");

        // Check if we are excluded in one of the directories containing the file.
        for(i=sizeof(path)-1; i>=0; i--) {
                dir = implode(path[0..i], "/");
                if( undefinedp(exclude_write[dir]) ) continue;
                if( member_array(euid, exclude_write[dir])!=-1 ) return 0;
                if( member_array(status, exclude_write[dir])!=-1 ) return 0;
        }

        // And then check if we are trusted in one of the directories containing
        // the file.
        if( member_array(euid, trusted_write["/"])!=-1 ) return 1;
        if( member_array(status, trusted_write["/"])!=-1 ) return 1;
        for(i=sizeof(path)-1; i>=0; i--) {
                dir = implode(path[0..i], "/");
                if( undefinedp(trusted_write[dir]) ) continue;
                if( member_array(euid, trusted_write[dir])!=-1 ) return 1;
                if( member_array(status, trusted_write[dir])!=-1 ) return 1;
        }

        log_file("FILES", sprintf("%s(%s) write attempt on %s failed.\n", geteuid(user), wizhood(user), file));
        return 0;
}

int valid_seteuid( object ob, string uid )
{
        if( uid==0 ) return 1;
        if( uid==getuid(ob) ) return 1;
        if( getuid(ob)==ROOT_UID ) return 1;
        if( sscanf(file_name(ob), "/adm/%*s") ) return 1;
        if( wiz_status[uid] != "(admin)"
        &&      wiz_status[getuid(ob)] == "(admin)" )
                return 1;
        return 0;
}
