// sanguandian.c ���ٵ�

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "���ٵ�");
	set("long", @LONG
���������ٵ�������й���˵�е���٣�Ң�����ع٣�˴�����˹٣�����
�С���ٴ͸����ع����ˮ�ٽ��֮˵����ǰ����ɽ�軨�����ɴִ��
�ϣ�û��֪���Ǻ��˺����ֵġ� 
LONG
	);
      

	set("exits", ([
		"southwest" : __DIR__"donglang5",
//		"north" : __DIR__"",
       ]));
	set("coor/x",-70);
	set("coor/y",320);
	set("coor/z",190);
	set("coor/x",-70);
	set("coor/y",320);
	set("coor/z",190);
	set("coor/x",-70);
	set("coor/y",320);
	set("coor/z",190);
	set("coor/x",-70);
	set("coor/y",320);
	set("coor/z",190);
	setup();
	replace_program(ROOM);
}



