// Room: /d/wuguan/changlang3.c
// Date: 99/05/30 by Byt

inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
���Ǹ����ȣ�����ͨ����Ϣ�ң���������Ʒ�������ﾲ���ĵģ�����
��·��ҲС������ģ��³��ű�����Ϣ������Ϣ���ˡ�
LONG );
        set("no_fight",1);
        set("outdoors", "wuguan");        
        set("no_steal",1);
        set("no_beg",1);
        set("exits", ([
                "south" : __DIR__"wupingfang",
                "north" : __DIR__"xiuxishi",                
        ]));
        setup();
        replace_program(ROOM);
}
