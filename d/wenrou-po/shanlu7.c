// shanlu7  ..angle
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", HIR"������"NOR);
        set("long", 
"����һ���ոտ�ʼ�޽�������֣����Կ����Ѿ����߹�ģ������Ъɽ
ʽ���߶��Ľṹ�����е�ľ���������þ�ѡ�Ϻõ��ľ�Ƴɣ�ʯ����������
ɽ�µĲ�ʯ���ɼ��������޴�ĺ��������ɷ����д��"+HIR+"������"+NOR+"�������֣�
���Ƕ�Ŀ��\n");
        set("no_clean_up", 0); 
        set("no_fight", 1);
        set("no_steal", 1);
         set("exits", ([
  "southdown" : __DIR__"shanlu6",])); 
        set("objects", ([
                __DIR__"npc/shitai" : 1,
                __DIR__"npc/xiao-nigu" : 2,
        ]));        set("coor/x",30);
	set("coor/y",-20);
	set("coor/z",70);
	set("coor/x",30);
	set("coor/y",-20);
	set("coor/z",70);
	set("coor/x",30);
	set("coor/y",-20);
	set("coor/z",70);
	set("coor/x",30);
	set("coor/y",-20);
	set("coor/z",70);
	setup();
}


