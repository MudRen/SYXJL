// tyroad5.c ���ɽ·
// by Marz 

inherit ROOM;

#include "feng.h"

void create()
{
	set("short", "���Ϸ�");
	set("long", @LONG
	���������Ϸ��ɽ·�ϣ�һ�����ͱڣ�һ�������£��߸ߵ�������(feng)
����������Լ�ɼ������ԵĽ���ͺ����˶���ϸ�ض����Լ��Ľ��£�����̧ͷ��һ�ۣ�
Ω��һ��С��ˤ��ȥ������ǿ�˳û���٣������޲�����������ֻ�����·��
LONG
	);
	set("outdoors", "wudang");

	set("exits", ([
		"northup" : __DIR__"wulao",
		"southdown" : __DIR__"wuyalin",
	]));

    set("item_desc", ([
        "feng" : (:look_feng:),
    ]));

	set("coor/x",-70);
	set("coor/y",120);
	set("coor/z",210);
	set("coor/x",-70);
	set("coor/y",120);
	set("coor/z",210);
	set("coor/x",-70);
	set("coor/y",120);
	set("coor/z",210);
	setup();
}

void init()
{
        add_action("look_feng", "look");
}
