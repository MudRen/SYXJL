// laocai.c



inherit NPC;

string inquiry_dao();



void create()

{

	set_name("�ϲ�", ({ "lao cai","cai" }) );

	set("gender", "����" );

	set("nickname","�ϲ�");

	set("age", 40);

	set("long", "һ�����������Ĺ����������տ����Ų�Ҳ�ܷ����Ƶġ�\n");

	set("shen_type",-1);

	set("combat_exp", 10000);

	set("str", 17);

	set("dex", 18);

	set("con", 18);

	set("int", 18);

        set("dao_count", 1);

	set("attitude", "friendly");

	set("inquiry" , ([

	"��" : (: inquiry_dao :),

	]));

	setup();

	carry_object("/clone/misc/cloth")->wear();

}



string inquiry_dao()

{

 object me=this_player();

 object ob;



    if (present("cai dao",me))

      return "�����ϴ���һ�ѣ�����Ҫ��\n";

        if (query("dao_count") < 1)

        return "���ڲ��Ѿ������ˡ�";

        add("dao_count", -1);

 ob=new("/d/baituo/obj/chaidao");

 ob->move(me);

       message_vision("�ϲĵݸ�$Nһ�Ѳ񵶡�\n",me);

      return "С�ı��ܣ�\n";

}

