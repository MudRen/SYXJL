// Room: /d/kunlun/jiuqulang1.c 

 

inherit ROOM; 

 

void create() 

{ 

        set("short", "������");

        set("long", @LONG

������ǰ���оŽ����������۵�������ˮ�档һ·������������ʯ�� 

Ȫ���仨������ˮɫ���ܡ����ߴ����������ӣ�������������ʯΪ������¥ 

��գ�ת�۴�����Сͤ��ӡ� 

LONG

        );

        set("no_clean_up", 0);

        set("exits", ([ /* sizeof() == 4 */

  "northwest" : __DIR__"jiuqulang2.c",

  "southeast" : __DIR__"guanhuat.c",

]));



        setup();

        replace_program(ROOM);

}



