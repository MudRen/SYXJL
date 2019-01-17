// hubudatang.c

#include <room.h>

inherit ROOM;

string look_sign(object me);

void create()
{
        set("short", "��������");
        set("long", @LONG
��������վ�ڻ��������������ר�����˸������ֵĵط���ȫ������
���������������Լ������ֲ������磬���ǵ���������Ǯ������
    �����ſڵĵط���һ����ľ��ɵ�����(sign)��
LONG
        );
        set("exits", ([
                "west" : __DIR__"marry_room",
                "east" : __DIR__"xingbudatang",
         ]) );

        set("objects", ([
		__DIR__"npc/shuji" : 1,
        ]));

        set("item_desc", ([
                "sign": (: look_sign :),
        ]) );
 
        set("coor/x",20);
	set("coor/y",140);
	set("coor/z",0);
	setup();
}

string look_sign(object me)
{
        return "�������ĸ��մ�����\n";
}

int valid_leave(object me, string str)
{
	if( me->query_temp("fee_paid") ) 
		me->delete_temp("fee_paid");
	return 1;
}