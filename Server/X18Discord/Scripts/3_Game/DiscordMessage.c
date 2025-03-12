class DiscordMessage
{
	string username = "USERNAME";
	string avatar_url = "AVATARURL";
	ref array<ref DiscordMessageEmbeds> embeds;
}
class DiscordMessageEmbeds
{
	ref array<ref DiscordMessageEmbedsFields> fields;
	ref DiscordMessageEmbedsThumbnail thumbnail;
}
class DiscordMessageEmbedsFields
{
	string name = "MESSAGETITLE";
	string value = "```MESSAGE```";
}
class DiscordMessageEmbedsThumbnail
{
	string url = "THUMBNAILURL";
}