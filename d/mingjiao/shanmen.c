// Room: /d/mingjiao/shanmen.c
// Date: XXL 97/04/3

#include <room.h>
inherit ROOM;

void create()
{
    set("short", "����ɽ��");
    set("long", @LONG
һ���޴����Ȼʯ�ź������Ƭɽ��֮�䣬ʯ�����Ϸ�����
��������������֣������̡����ּ���Щ���䣬����ȥ�����Զ��
��λ��ʮ����Ĵ��ֳָֽ�����ɽ�����ࡣ
LONG
    );

    set("exits", ([
        "westup" : __DIR__"shanlu1",
        "east" : __DIR__"tomen1",
    ]));

    set("valid_startroom","1");    
    set("outdoors", "mingjiao");
    set("objects",([
        __DIR__"npc/menwei1" : 2,
        __DIR__"npc/jieyinshi":1,
        __DIR__"npc/chengchaofeng":1,
    ]));
    set("coor/x",-130);
	set("coor/y",-70);
	set("coor/z",0);
	setup();
//    replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
    object *inv;
    mapping myfam, mygen;
    int i;

    myfam = (mapping)me->query("family");

    if ((!myfam || myfam["family_name"] != "����"||myfam["family_name"] != "�䵱��" ) && dir == "westup") {
        inv = all_inventory(me);
        for(i=sizeof(inv)-1; i>=0; i--)
            if(inv[i]->query("weapon_prop") && (inv[i]->query("wielded")))
                if(objectp(present("meiwei1", environment(me))))
                    return notify_fail("����ס��˵������λ" +
                        RANK_D->query_respect(me) + "����±��С��ҽ̹̽���"
			"������Ͳ�\n�óֱ�����ɽ������¡�\n");
    }
    return ::valid_leave(me, dir);
}
