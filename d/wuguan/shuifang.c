// Room: /d/wuguan/shuifang.c
// Date: 99/05/30 by Byt

inherit ROOM;
void create()
{
        set("short", "ˮ��");
        set("long", @LONG
һ���ݣ��㿴�����ڷ��ż��ڴ�ף�������װˮ�õģ��������ƺ�����
�յģ�����û��һ���ˣ��������˶����ˡ�
LONG );
        set("no_fight",1);
        set("no_steal",1);
        set("no_beg",1);
        set("exits", ([
                "east" : __DIR__"houyuan",
        ]));
        setup();
        replace_program(ROOM);
}
