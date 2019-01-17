// roommaker.c

// for ESLib

#define RMK_VERSION "(v3.0)"

#include <localtime.h>

inherit ITEM;

inherit F_AUTOLOAD;



int done_setlong(object me,string long);

int done_rdesc(object me, string arg,string desc);

string *special_props = ({

        "short", "long" });



nosave mapping map_dirs = ([
  "east"        :       "west",

  "west"        :       "east",

  "north"       :       "south",

  "south"       :       "north",

  "northeast"   :       "southwest",

  "southwest"   :       "northeast",

  "northwest"   :       "southeast",

  "southeast"   :       "northwest",

  "northup"     :       "southdown",

  "southup"     :       "northdown",

  "eastup"      :       "westdown",

  "westup"      :       "eastdown",

  "northdown"   :       "southup",

  "southdown"   :       "northup",

  "eastdown"    :       "westup",

  "westdown"    :       "eastup",

  "up"          :       "down",

  "down"        :       "up",

]);



nosave mapping abbr_dir = ([
        "n"     :       "north",

        "s"     :       "south",

        "e"     :       "east",

        "w"     :       "west",

        "nu"    :       "northup",

        "su"    :       "southup",

        "eu"    :       "eastup",

        "wu"    :       "westup",

        "nd"    :       "northdown",

        "sd"    :       "southdown",

        "ed"    :       "eastdown",

        "wd"    :       "westdown",

        "ne"    :       "northeast",

        "nw"    :       "northwest",

        "se"    :       "southeast",

        "sw"    :       "southwest",

        "u"     :       "up",

        "d"     :       "down",

]);



string abbrdir(string dir)

{

        if (!undefinedp(abbr_dir[dir])) 

                return abbr_dir[dir];

        else return dir;

}



int save_room_file(string yn, string file, string str);



void create()

{

        set_name("����༭��" + RMK_VERSION, ({ "roommaker", "maker" }) );

        set_weight(100);

        set("unit", "��" );

        set("long", @LONG

����һ�����������١����췿��Ĺ��ߣ�����ʱ�䲻���������  lag ����ʦ

����������������򵥵ķ��䣬���������������Լ����򷿼��Ʒ�ʣ����

��Ҫ̫������������������ʹ�����¼���ָ�



mkroom <���䵵��>                     delset <��������>

���һ�����ա����䣬 goto ��          ɾ����������

��������� �趨��������ԡ�           

                                      rnpc <����> <����>

rset <��������> <��������>            �趨������Ʒ��������

�趨��Ŀǰ���ڷ�������ԣ���          

no_fight��sleep_room                  rsave

valid_startroom                       ʹ�� -h ������    

outdoors �ȡ�                         Ŀǰ���ڵķ���浵��

                                      ������Ա����ӵķ���

rgo <����> <���䵵��>                 Ҳһ��浵��                    

����Ŀǰ���ڵķ�������һ����

�ڵ���һ�����䡣��������д��          rname <����>                             

���䵵��=none��ɾ���������         ���ķ������� 

          

rlong <����>                          rdesc<����> 

����Ŀǰ����������                    ���ӻ��޸�һ��item_desc

LONG

        );

}



int query_autoload() { return 1; }



void init()

{

        if( wizardp(environment()) ) {

                seteuid(getuid(environment()));

                add_action("do_mkroom", "mkroom");

                add_action("do_rset", "rset");

                add_action("do_connect", "rgo");

                add_action("do_saveroom", "rsave");

                add_action("do_roomname", "rname");

                add_action("do_roomlong", "rlong");

                add_action("do_delset", "delset");

                add_action("do_npc", "rnpc");

                add_action("do_rdesc", "rdesc");

        }

}



int do_npc(string arg)

{

        mapping objects;

        int i;

        string file;



        if( !arg || sscanf(arg, "%s %d", file,i)!=2 )

                return notify_fail("ָ���ʽ��rnpc <����> <����>\n");

        file = resolve_path(this_player()->query("cwd"), file);

        objects = environment(this_player())->query("objects");

        if( mapp(objects) )

                objects[file] = i;

        else

                environment(this_player())->set("objects", ([ file : i ]) );

        write("Ŀ���趨��ϡ�\n");

        return 1;

}





int do_roomname(string arg)

{

        if(!arg)

        return notify_fail("ָ���ʽ��rname <��������>\n");

        environment(this_player())->set("short", arg);

        write("���Ƹ�����ϡ�\n");

        return 1;

}



int do_delset(string arg)

{

        if(!arg)

        return notify_fail("ָ���ʽ��delset <��������>\n");

        environment(this_player())->delete(arg);

        write("����ɾ����ϡ�\n");

        return 1;

}





int do_roomlong()

{

        this_player()->edit( (: done_setlong, this_player():) );

        return 1;

}

int done_setlong(object me, string long)

{

        environment(this_player())->set("long", long);

        write("����������ϡ�\n");

        return 1;

}



int do_rdesc(string arg)

{

        if( !arg ) return notify_fail("��������һ�����ơ�\n");

        this_player()->edit( (: done_rdesc, this_player(), arg:) );

        return 1;

}



int done_rdesc(object me, string arg,string desc)

{

        environment(this_player())->add("item_desc", ([ arg : desc ]) );

        write("OK��\n");

        return 1;

}



int do_mkroom(string arg)

{

        string file, dir;


        if( !arg ) return notify_fail("ָ���ʽ��mkroom <���䵵��> [<����>]\n");

        if( sscanf(arg, "%s %s", file, dir)!=2 )

                file = arg;

        seteuid(geteuid(this_player()));

        file = resolve_path(this_player()->query("cwd"), file) + ".c";

        if( file_size(file)!=-1 )

                return notify_fail("���� " + file + " �Ѿ������ˡ�\n");

        if( !write_file(file, @ROOM_CODE

// This is a room made by roommaker.



inherit ROOM;



void create()

{

        set("short", "�շ���");

        set("long", "-----------����һ��ʲ��Ҳû�еĿշ��䡣---------------------\n");

        setup();

        replace_program(ROOM);

}

ROOM_CODE

        ) ) return notify_fail("��û��д�뵵��(" + file +")��Ȩ����\n");

        message_vision("ֻ����$N�ķ���༭�����١���һ�����������������ֱ����һ�㡣\n", this_player());

        return 1;

}



int do_rset(string arg)

{

        string prop, str;

        mixed data;



        if( !arg || sscanf(arg, "%s %s", prop, str)!=2 )

                return notify_fail("ָ���ʽ��rset <��������> <��������>\n");



        if( sscanf(str, "%d", data)!=1 )

                data = str;



        environment(this_player())->set(prop, str);

        write("Ok.\n");

        return 1;

}



int do_connect(string arg)

{

        mapping exits;

        string dir, file;

        object room;



        if( !arg || sscanf(arg, "%s %s", dir, file)!=2 )

                return notify_fail("ָ���ʽ��connect <����> <���䵵��>||<none>\n");



        dir = abbrdir(dir);



        if (file=="none"){

                environment(this_player())->delete("exits/"+dir);

                write("ɾ������...Ok.\n");

                return 1;

        }



        file = resolve_path(this_player()->query("cwd"), file);

        exits = environment(this_player())->query("exits");



        if( mapp(exits) )

                exits[dir] = file;

        else

                environment(this_player())->set("exits", ([ dir: file ]) );



        if( !undefinedp(map_dirs[dir]) ) 

                if( room = load_object(file) ){

                        exits = room->query("exits");

                        if( mapp(exits) )

                                exits[map_dirs[dir]] = 

                                resolve_path(this_player()->query("cwd"),

                                base_name(environment(this_player())));

                        else

                                room->set("exits",([ map_dirs[dir]: 

                                resolve_path(this_player()->query("cwd"),

                                base_name(environment(this_player()))) ]) );

                } 



        write("ͨ���趨��ϡ�\n");

        return 1;

}



int saveroom(string file,object me)

{

        object env;

        string str, *name,username,changtime,*temp,temp1;

        mapping prop;

        int i,flag;

        mixed *thistime;



        temp1 = "";

        env = load_object(file);

        temp = explode (read_file (file), "\n");



        for (i=0; i<sizeof (temp); i++){

                if (strsrch(temp[i], "create()") != -1 )

                        flag = 1;

                if( flag == 1 && strsrch(temp[i], "setup()") != -1 )

                        flag = 2;

                else if( flag == 2 )

                        temp1 += temp[i]+"\n";

        }

//add by liuwu 1998.10.13

        username=this_player()->query("name")+"("+me->query("id")+")";

        thistime=localtime(time());

        changtime=sprintf("��Ԫ��%d��%d��%d�գ�����ʱ�䣺%dʱ%d��%d�롣",

               thistime[LT_YEAR],thistime[LT_MON]+1,thistime[LT_MDAY],

               thistime[LT_HOUR],thistime[LT_MIN],thistime[LT_SEC]);    



        str = "// Room: " + file 

              + "\n// Data: "+ username 

              + "\n// Time: "+ changtime



              + @ROOM_CODE





inherit ROOM;



void create()

{

ROOM_CODE

        ;

        str += sprintf("\tset(\"short\", %O);\n", env->query("short") );

        str += sprintf("\tset(\"long\", @LONG\n%sLONG\n\t);\n", env->query("long") );

        prop = env->query_entire_dbase();

        name = keys(prop);

        for(i=0; i<sizeof(name); i++) {

                if( member_array(name[i], special_props)!=-1 ) continue;

                str += sprintf("\tset(\"%s\", %O);\n", name[i], prop[name[i]] );

        }

        str += "\n\tsetup();\n";

        str += temp1;

        // Replace current directory with __DIR__ macro to make relocatable code.

        i = strlen(file)-1;

        while( (i > 0) && (file[i]!='/')) i--;

        if( i>0 ) {

//                write("ĿǰĿ¼��" + file[0..i] + " �� __DIR__ ȡ����\n");

                str = replace_string(str, "\"" + file[0..i], "__DIR__\"");

        }



//        if( file_size(file)!=-1 ) {

//                write("���� " + file + " �Ѵ��ڣ�Ҫɾ���ɵ���[y/n]");

//                input_to("save_room_file", file, str);

//                return 1;

//        }



       return save_room_file("y", file, str);



}



int save_room_file(string yn, string file, string str)

{

        if( strlen(yn)<1 || yn[0]!='y' ) return 1;



        rm(file);

        write("�浵 " + file + "....");

        if( write_file(file, str) ) {

                write("Ok.\n");

                return 1;

        } else

                return notify_fail("��û��д���������(" + file + ")��Ȩ����\n");

}



void owner_is_killed() { destruct(this_object()); }



int do_saveroom(string arg)

{

        object env,me;

        string file;

        mapping exits;

        mixed exit;

        int i;



        me = this_player();

        env = environment(me);

        file = file_name(env) + ".c";



        saveroom(file,me);



        if( arg != "-h" && !arg ){

                exits = env->query("exits");

                exit = keys(exits);

                for(i=0;i<sizeof(exit);i++){

                        if( load_object(exits[exit[i]]) ){

                                file = exits[exit[i]]+".c";

                                saveroom(file,me);

                        }

                }

        }

        return 1;

}



