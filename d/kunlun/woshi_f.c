 // Room: /d/kunlun/woshi_f.c 

 

inherit ROOM; 

 

void create() 

{ 

        set("short", "Ů��������");

        set("long", @LONG

��������Ů���ӵ�ס�����������м��軨�ܣ����԰���һ����¯,һ 

�����̻�����Ʈ����������������˯����ǽ��������ľ��, ֻ���ý���ϸ 

ϸ, ����Ů����������Ϣ�� 

LONG

        ); 

        set("sleep_room",1);        set("no_fight", "0");

        set("no_clean_up", 0);

        set("exits", ([ /* sizeof() == 1 */

  "east" : __DIR__"dalgf_1",

]));



        setup();

        replace_program(ROOM);

}



