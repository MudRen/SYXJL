inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
佻�Ϫ�ɺ�«״���ڴ�һ�������������������ƻ�żפ��Զ���ƻ���㣬������Ӱ
ө�⣬�����ѱ档����ʱ��˪����𣬷��ֽ�Ⱦ�Ʊ̣�Ұ��˥��ܽ�أ���ӳˮ�ʣ�«έ
�к���Ⱥ������߿���ƣ��������ˡ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"bridge2",
  "south" : __DIR__"podi",
  
]));
   
	set("outdoors","huanhua");
        set("coor/x",40);
	set("coor/y",-100);
	set("coor/z",0);
	set("coor/x",40);
	set("coor/y",-100);
	set("coor/z",0);
	set("coor/x",40);
	set("coor/y",-100);
	set("coor/z",0);
	set("coor/x",40);
	set("coor/y",-100);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}