inherit ROOM;

void create()
{
        set("short", "����");
        set("long",@LONG
�������������´���ǰ��ֻ�����ƻֺ�������������Ͽ���һ������
( duilian )�����Ḳ�֣����е㲦����֮�⡣̧ͷ�����������һ���
ľ���ң����⡰��ʥ�¡��������֣�������ɡ�������ʽ�������������
�Խй��ˣ�����֮Ϊ�������¡���
LONG
        );
        set("outdoors", "tianlongsi");
        set("exits", ([
                "south" : __DIR__"talin",
                "north" : "/d/dali/hongsheng",
        ]));
         set("item_desc",([
          "duilian" : "\n    ������Ⱦ����Բ�ɡ�������Ե�������\n\n",
                          ]));  
         set("objects",([
                 __DIR__"npc/zhikeseng" : 1,
          ]));
        set("coor/x",0);
	set("coor/y",-60);
	set("coor/z",10);
	set("coor/x",0);
	set("coor/y",-60);
	set("coor/z",10);
	set("coor/x",0);
	set("coor/y",-60);
	set("coor/z",10);
	set("coor/x",0);
	set("coor/y",-60);
	set("coor/z",10);
	setup();
        replace_program(ROOM);
}
