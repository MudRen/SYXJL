// Room: /d/wuguan/wuguandayuan.c
// Date: 99/05/30 by Byt

inherit ROOM;
void create()
{
        set("short", "��ݴ�Ժ");
        set("long", @LONG
���Ǹ���Ժ�ӣ��������߶������䳡��������������ϰ��ǿ������
�ܳ����Һ��ģ��㿴����ʱ�п��Ŷ����ģ�����ˮ�ĴҴҶ�����������
��̨�׾�����ݴ�����
LONG );
        set("no_fight",1);
        set("no_steal",1);
        set("no_beg",1);
        set("exits", ([
                "south" : __DIR__"wuguangate",
                "north" : __DIR__"wuguandayuan1",   
                "east"  : __DIR__"changlang1",                             
                "west"  : __DIR__"changlang5",                                             
                 "southwest"  : __DIR__"liaotian",             
        ]));
        set("objects", ([
                __DIR__"npc/brave" : 1,
        ]));        
        setup();
        replace_program(ROOM);
}
