#include <room.h>
inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
һ�������Ĺ������������Զ���ǽ��ÿ�������ɣ�ǽ�϶�����һ֧����
�εľ���
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"liangongfang",
  "east" : __DIR__"changlang4",
  "west" : __DIR__"qianqiudian",
]));
        set("no_clean_up", 0);
set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/yang" : 1,
  __DIR__"npc/shizhe" : 2,
]));

        setup();
}

int valid_leave(object me, string dir)
{
        mapping myfam;
        myfam = (mapping)me->query("family");

        if ((!myfam || myfam["family_name"] != "�������") && dir == "north" &&
                objectp(present("yang", environment(me))))
           return notify_fail("����ͤ�ȵ����㲻��������̵��ӣ��������ڡ�\n");
                
        return ::valid_leave(me, dir);
}
