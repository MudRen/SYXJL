// �޸� by think

#include <ansi.h>
#include <room.h>


inherit ROOM;
string look_mupai();
void create ()
{
        set ("short", "���䳡����");
        set ("long", @LONG
���ǡ���Եϴ��¼���ı��䳡�Ĵ��ţ�һ���߸ߵ�ľ���Ʒ������顺���䳡��
�����ֽ���֡����ﾭ���ٰ�������͵ı����ᡣ���е��˶��л���μӡ�
�Ա�����һ�����ߵ�ľ��(mupai)�����治֪д��ʲô��
LONG);
        set("no_fight",1);
        set("no_clean_up",1);
        set("item_desc", ([
                "mupai" : (:look_mupai:),
        ]));

        set("exits", ([
                "north"   : __DIR__"zoulang",
                "south"   : "/d/city/chatroom",
        ]));
        set("objects", ([
                "/u/think/biwu/npc/gongping" : 1,
        ]));
        setup();
}

int valid_leave(object me, string dir)
{
        object ob, where;

        if (!where=find_object(__DIR__"gate"))
                where=load_object(__DIR__"gate");
        ob=present("gongping zi", where);
        if ( !wizardp(me) && dir=="north" )
            if( ob->query("fangshi")!="������" && !ob->query("start/start"))
       return notify_fail("����û���κα��䣬�㲻�ܽ�ȥ��\n");
        return ::valid_leave(me, dir);
}

string look_mupai()
{
        return "\n\n"HIG"����list����鿴�������������\n\n����family�����������ɱ��䡣\n\n
����canjia����μӱ��䡣\n\n"+NOR"";

}

