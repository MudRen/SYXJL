inherit ROOM;

void create()
{
    set("short", "�ͷ�");
    set("long", @LONG
����ר����������Ϣ�Ŀͷ���������軪�������Ϲ��Ŵ�
�徫���Ĵ��������ڵ�һ����������ŵ�ľ����ȴ���Ե�ӵ
����������������һ�����ӣ������һ����������ɱ���һ
Щ��㡣�ݽ��м�Ͳ��ˮ��
LONG );
    set("exits", ([
    "east"  : __DIR__"qianyuan1",
    ]));
    
    set("objects", ([
        __DIR__"obj/cha" : random(2),
        __DIR__"obj/gao"  : random(3),
    ]) );    
    set("no_fight",1);
    set("sleep_room","1") ;
    set("resource/water", 1);
    
    set("coor/x",0);
	set("coor/y",-40);
	set("coor/z",0);
	set("coor/x",0);
	set("coor/y",-40);
	set("coor/z",0);
	set("coor/x",0);
	set("coor/y",-40);
	set("coor/z",0);
	set("coor/x",0);
	set("coor/y",-40);
	set("coor/z",0);
	setup();
    replace_program(ROOM);
}

