inherit ROOM;

void create()
{
        set("short", "ɽ��");
        set("long", @LONG
�����Ƕ���ɽ��ɽ�ţ�ӭ��һ���ߴ�ĺ�����ɽ�š�ʯ�״�ɽ���´�
����ɽ�ŵĺ�����һ����ΰ�Ĵ��Ǿ��Ƕ��ҵ�ɽ�ŵɽ������һȺ
�����ɵ���ɽ�����ڼ��������ˣ����Ƕ����ɵĲ�����ɽ������һ����
�����������ڽӴ����������ɵ����ѡ�
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"shmdian",
  "westdown" : __DIR__"yunvchi",
]));
        set("no_clean_up", 0);
        set("objects",([
               __DIR__"npc/wenxu" : 1, 
               __DIR__"npc/shoushan" : 4,  
            ]));         
        set("coor/x",-30);
        set("coor/y",-30);
        set("coor/z",60);
        set("coor/x",-30);
        set("coor/y",-30);
        set("coor/z",60);
        set("coor/x",-30);
        set("coor/y",-30);
        set("coor/z",60);
        setup();
}

