// Room: /d/xingxiu/xxroad3.c

inherit ROOM;

void create()
{
        set("short", "����ɽ");
        set("long", @LONG
����һ����̫�ߵ�Сɽ��ɽ����ȥ�����������(sky)Ʈ�ż��䵭����
���ơ�һȺ���㷢�����¸¡��Ľ�������ͷ�Ϸɹ�������ɽ�³��ǵĲ�ԫ��
����ϡ�ɱ档���ǵľ�ͷ��һ����ΰ�Ĺذ���·����һ������֮�Ͽ����״�
(poem)��
LONG
        );
        set("exits", ([
  "westdown" : __DIR__ "jiayuguan",
  "southdown" : __DIR__"xxroad2",
]));

        set("item_desc", ([ 
"poem" : "�±��Ͽ���һ����ƽ�֣�

  ��  ��  ��  ��  ��  ��  ��  ��
  ʱ  ��  ��  ��  ָ  ��  ��  ��
  ��  ��  ��  ɽ  ��  ��  ��  ��
  ��  ӧ  ��  ��  ��  ��  ��  ��
  ��  ��  ��  ��  ��  ��  ��  
  ��  ��  ��  ��  ��  ��  
                      ��

�������Ǻú��ˣ�
\n",
"sky" : "
                              \\/             \\/
                   /*=*         \\/       \\/
                   (*=*=)         \\/  \\/
               {/*=**=/            \\/
                         __
                        /\\.\\_   
               /\\  /\\  /  ...\\   /\\
              / .\\/ .\\/    .. \\_/ .\\
             /  ..\\  /    ... . \\  .\\      /\\
            /͹͹͹\\/͹͹͹. ..͹\\͹.\\    / .\\  
  _͹͹͹͹/     ..͹     ͹͹͹..\\__.\\͹/  ..\\_͹͹͹͹͹͹͹͹͹͹͹͹_\n\n"
]));

        set("no_clean_up", 0);
        set("outdoors", "����");

        set("coor/x",-50);
	set("coor/y",10);
	set("coor/z",10);
	set("coor/x",-50);
	set("coor/y",10);
	set("coor/z",10);
	set("coor/x",-50);
	set("coor/y",10);
	set("coor/z",10);
	set("coor/x",-50);
	set("coor/y",10);
	set("coor/z",10);
	setup();
        replace_program(ROOM);
}
