// Room: /d/kunlun/tieqinju.c 

 

inherit ROOM; 

 

void create() 

{ 

        set("short", "���پ�");

        set("long", @LONG
����ԭ�ǵ����������ź�̫���ס��������������������谮������ˣ��� 
�������ڴˣ��ʴ˴����Ѿ���ȥ��ǽ��Ҳ�տյ��������䰮���ֻ����Ƶ������ 
������ȥ�ˣ�ֻʣ�¿�ǽ��һ�ż��������Ϸ��������˵�����(tieqin)�������� 
һ�ѷ��� (fuchen)�� 

LONG

        );

        set("no_clean_up", 0);

        set("exits", ([ /* sizeof() == 2 */

  "west" : __DIR__"sleeproom",

  "south" : __DIR__"zoul_5",

]));

        set("item_desc", ([ /* sizeof() == 2 */

  "fuchen" : "�����������ٵķ���, ����β�Ƴ�

",

  "tieqin" : "һ�ź����������

",

]));

        set("objects", ([ /* sizeof() == 3 */

   "/d/kunlun/npc/kl-dizi4.c" : 1,

   "/d/kunlun/npc/kl-dizi2.c" : 1,

  __DIR__"npc/hetaichong.c" : 1,

]));



        setup();

        replace_program(ROOM);

}



