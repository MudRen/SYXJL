inherit ROOM;

void create()
{
        set("short", "Сʯ��");
        set("long", @LONG
ʯ���ڿ���һ���������ǽ֮�⣬��һ���Ҿ߶�û�У������ڵ�ʮ��
�ɾ���һ����Ⱦ����Ȼ������������ɨ�ġ�
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
		"east" : __DIR__"houhuayen",
]));
        set("no_clean_up", 0);

        setup();
}

void init()
{
	object book, me;
	me = this_player();
	
	add_action("do_break", "break");
	if ((objectp(book=present("kuihua baodian",me)))) {
		remove_call_out("buqun_rob");
		call_out("buqun_rob", 1, me, book);
	}
}

int do_break(string arg)
{
        int n;
        n = this_player()->query("neili");
        if( !arg && arg!="��" && arg!="wall") {
                write("����Ϊ����Դ���ʯ����\n");
                return 1;
        }


        message_vision(
        "$Nʰ��һ�鶷��ʯͷ��������ʯ������ȥ��\n", this_player());

        if (n>=1000) {
        message_vision(
        "��Ȼ�ص�һ���죬ʯͷ����ʯ�ڣ�ʯ��������һ���󶴣�\n", this_player());
        set("exits/down",  __DIR__"biguan");
        this_player()->set("neili",n-400);
        remove_call_out("close");
        call_out("close", 5, this_object());
        }
        else {
        message_vision(
        "$N���һ����˫ȭ�ʹ򣬵�����û�ã�����$N����������ǿ��\n", this_player());
        this_player()->set("neili",0);
        }

        return 1;
}

void close(object room)
{
        message("vision","ʯ���ϵ���ʯ��ס�����������ֶ�ס�˴󶴡�\n", room);
        room->delete("exits/down");
}
