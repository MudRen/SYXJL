inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
����ï�ܣ��������֮�䣬һ�����ĵ����������֣�����Ǳ���Ϊ����
�ֲط������ķ������ˡ��˴������ž�����ɫ���ˣ����ܵ����������֮�䣬
ȴ����û�л���Ʈ�������İ�Ҷ���ݶ��Եøɸɾ�����������ɽ�罫��Ҷ����
���˰ɡ��º������޷�ɽ��������Ƕ�üʮ��֮һ���������޷���ơ�������
���ǽ������ˡ�
LONG
        );

        set("exits", ([
                "eastup" : __DIR__"jietuo",
                "west" : __DIR__"bgsgate",
                "north" : __DIR__"luofeng",
               ]));
        set("coor/x",-50);
	set("coor/y",-50);
	set("coor/z",20);
	set("coor/x",-50);
	set("coor/y",-50);
	set("coor/z",20);
	set("coor/x",-50);
	set("coor/y",-50);
	set("coor/z",20);
	setup();
        replace_program(ROOM);
}