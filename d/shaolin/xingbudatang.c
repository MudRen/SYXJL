// xingbudatang.c  �̲�����

#include <room.h>

inherit ROOM;

string look_sign(object me);

void create()
{
        set("short", "�̲�����");
        set("long", @LONG
��������վ���̲�������������ƹܸ����̷��ĵط���
    �����ſڵĵط���һ����ľ��ɵ�����(sign)��
LONG
        );
        set("exits", ([
                "west" : __DIR__"hubudatang",
               "north":"/d/city/postport",
         ]) );

        set("objects", ([
		__DIR__"npc/kuli" : 1,
        ]));

        set("item_desc", ([
                "sign": (: look_sign :),
        ]) );
 
        set("coor/x",30);
	set("coor/y",140);
	set("coor/z",0);
	setup();
}

string look_sign(object me)
{
        return "�����ʦ��¼��\n";
}

int valid_leave(object me, string str)
{
	if( me->query_temp("fee_paid") ) 
		me->delete_temp("fee_paid");
	return 1;
}
