inherit ROOM;

void create()
{
    set("short", "С��");
    set("long", @LONG
����ר��������Ϣ��С�ݡ�������������Ŵ���������ռ�������ӵ�һ���
�ط����ݽǺ�ɢ�ҵط���һЩ�ճ������þߡ��������һ�����ӣ������һ
����ͼ������ӡ�
LONG );
set("exits", ([
    "east"  : __DIR__"houyuan",
]));
set("objects", ([
        __DIR__"npc/puren" : 3,
    ]) );    

    
    set("sleep_room","1") ;
    set("coor/x",40);
	set("coor/y",-240);
	set("coor/z",0);
	setup();
    replace_program(ROOM);
}
