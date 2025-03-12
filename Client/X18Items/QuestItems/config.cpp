class CfgPatches
{
	class X18_QuestItems
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.100000;
		requiredAddons[] = { "DZ_Data" };
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class FS_Document_1;
	class FS_Document_3;
	class FS_PREDMET_Noutbuk;
	class X18_Quest_Burned : Inventory_Base
	{
		scope = 2;
		displayName = "Dokumente (Zerstört)";
		descriptionShort = "Du kannst diese Dokumente nicht lesen da sie leider bereits zu stark zerstört sind.";
		weight = 125;
	};
	class X18_Quest_ANoteToFang : Inventory_Base
	{
		scope = 2;
		displayName = "#STR_ANoteToFang";
		descriptionShort = "#STR_DSC_ANoteToFang";
		weight = 500;
		model = "DZ\gear\consumables\paper.p3d";
	};
	class X18_Quest_ANoteToGhost : Inventory_Base
	{
		scope = 2;
		displayName = "Eine Notiz an Ghost";
		descriptionShort = "Ghost, ich nehme meine Sachen. Danke für das Sturmgewehr - ich werde es brauchen. Im Gegenzug überlasse ich Ihnen einiges an medizinischer Versorgung des Doktors. Ich habe es geschafft, den Söldner zu fangen, der mir auf der Spur war, also werde ich sie nicht brauchen ... Ich hoffe. Ich werde Fang jetzt treffen - er hat es geschafft, den Decoder zusammenzubauen. Treffen wir uns am üblichen Ort, wenn Sie es schaffen. Strelok.";
		weight = 500;
		model = "DZ\gear\consumables\paper.p3d";
	};
	class X18_Quest_ANoteToStrelok : Inventory_Base
	{
		scope = 2;
		displayName = "Eine Notiz an Strelok";
		descriptionShort = "Strelok, ich habe den anderen Decoder für alle Fälle in unserem Pripyat-Vorrat gelassen. Ich und Ghost fahren nach Agroprom, also lassen wir unsere zusätzliche Munition hier. Nimm sie, wenn du es brauchst. Fröhliches Jagen! Fang.";
		weight = 500;
	};
	class X18_Quest_NotebookExperiment : FS_Document_3
	{
		scope = 2;
		displayName = "Beschreibung über ein Experiment";
		descriptionShort = "Das Notizbuch enthält eine detaillierte Beschreibung eines Experiments zur Bewertung der Wirkung eines Psy-Feldes auf ein Objekt in einer anderen Hemisphäre. Eine Gruppe von Wissenschaftlern in der Karibik empfing das Signal, aber es war verzerrt. Das Signal wurde auf seltsame Weise verändert, als ob es von jemandem korrigiert worden wäre. Eine mögliche Erklärung ist, dass die Noosphärentheorie korrekt ist und die Änderungen von der Noosphäre vorgenommen wurden. Diese Dokumente dürfen nicht in die Hände anderer fallen, da sie für USS-Analysten von großem Interesse wären.";
		weight = 500;
	};
	class X18_Quest_AdmistrativeDocuments : FS_Document_1
	{
		scope = 2;
		displayName = "Administrative Dokumente";
		descriptionShort = "Ein Ordner mit Dokumenten, die rein administrative Informationen enthalten. Gemäß den Unterlagen wurde auf Anordnung des Zentrallabors die technische Dokumentation zu Projekt-62 an die Prüfwerkstatt übergeben.";
		weight = 500;
	};
	class X18_Quest_DeliverySchedule : Inventory_Base
	{
		scope = 2;
		displayName = "Lieferungsplan";
		descriptionShort = "Zeitplan für Lieferungen von Projekt-62: 07/14 - 20 Einheiten (eine beschädigt); 21.07 - 32 Einheiten (2 beschädigt); 28.07. - 26 Einheiten (eine beschädigt). Der Frachtbrief über Verluste auf dem Weg wurde an die Werksverwaltung gesendet, eine Kopie an die Reparaturwerkstatt.";
		weight = 500;
		model = "DZ\gear\consumables\paper.p3d";
	};
	class X18_Quest_DecumentsItem62 : FS_Document_1
	{
		scope = 2;
		displayName = "Unterlagen zu Projekt-62";
		descriptionShort = "Ein Ordner mit Dokumenten, die rein administrative Informationen enthalten. Gemäß den Unterlagen wurde auf Anordnung des Zentrallabors die technische Dokumentation zu Projekt-62 an die Prüfwerkstatt übergeben.";
		weight = 500;
	};
	class X18_Quest_DocumentsWithNotes : FS_Document_1
	{
		scope = 2;
		displayName = "Dokumente mit Notizen";
		descriptionShort = "In den Dokumenten wird erwähnt, dass gemäß einer Anordnung der Abteilung 1 nach dem Verschließen der Transportschleuse die Unterführung Pripyat 1 mit Kohlendioxid geflutet wurde, das mit einem chemischen Zusatzstoff gemischt war. Infolgedessen wurden alle Mitarbeiter angewiesen, Chemikalienschutzanzüge mit Atemmodulen mit geschlossenem Kreislauf zu tragen.";
		weight = 500;
	};
	class X18_Quest_DutyShiftLog : Inventory_Base
	{
		scope = 2;
		displayName = "Duty Schichtprotokoll";
		descriptionShort = "... 18:30 - luftdichte Abdichtung aller P-1-Unterführungsteile abgeschlossen. 19:00 - luftdichte Abdichtung der Eisenbahnschloss-Türen abgeschlossen. Zum Abdichten der Türen musste geschweißt werden. Der Betrieb des Schließtürmechanismus erforderte die Aktivierung des Notstromaggregats, da die Stromzufuhr zur Unterführung bereits unterbrochen worden war. 20:00 - Die chemische Werkstatt hat die Überflutung der Unterführung mit Gas eingeleitet. 22:00 Uhr - Die Arbeiten zur Abdichtung der Unterführung sind abgeschlossen. Alle Dokumente wurden an Abteilung 1 gesendet.";
		weight = 500;
		model = "DZ\gear\consumables\paper.p3d";
	};
	class X18_Quest_FolderWithTheOrder : FS_Document_1
	{
		scope = 2;
		displayName = "Ordner mit Dienstanweisung";
		descriptionShort = "In den Dokumenten wird die Evakuierung des Produktionskomplexes aus dem Jupiter-Werk in unterirdische Labors erwähnt. Diese Angelegenheit sollte im Laborteil besprochen worden sein.";
		weight = 500;
	};
	class X18_Quest_InternalOrderNo423_1 : FS_Document_3
	{
		scope = 2;
		displayName = "Interne Anordnung Nr. 423 (Teil 1)";
		descriptionShort = "Streng geheim. Befehl von Colonel P.P. Slavin. Gemäß dieser Anordnung sind die Mitglieder der Chemikalienschutzeinheit Nr. 423 mit den folgenden Informationen vertraut zu machen: 1. Die Schlüssel für den Behälter mit der chemischen Lösung Perin B3 werden von Colonel P.P. Slavin (Schlüssel A) und Oberst ...";
		weight = 500;
	};
	class X18_Quest_InternalOrderNo423_2 : FS_Document_3
	{
		scope = 2;
		displayName = "Interne Anordnung Nr. 423 (Teil 2)";
		descriptionShort = "... leutnant K.S. Wlassow (Schlüssel B). 2. Konvoi-Befehl von vorne: Fahrzeug des stellvertretenden Befehlshabers, Begleitfahrzeug Nr. 8, APC Nr. 1, Transportfahrzeug Nr. ...";
		weight = 500;
	};
	class X18_Quest_InternalOrderNo423_3 : FS_Document_3
	{
		scope = 2;
		displayName = "Interne Anordnung Nr. 423 (Teil 3)";
		descriptionShort = "... 1, APC Nr. 3, Begleitfahrzeug Nr. 2, Fahrzeug des Befehlshabers der Einheit (P.P. Slavin). Kopien des Befehls an Oberstleutnant K.S. Vlasov und Oberleutnant R.B. Nazarenku.";
		weight = 500;
	};
	class X18_Quest_LetterConcerningItem62 : Inventory_Base
	{
		scope = 2;
		displayName = "Schreiben über Lieferungen von Projekt-62";
		descriptionShort = "Aufgrund anomaler Aktivitäten ist ein Transport von Projekt-62 über offenes Gelände nicht möglich. Verwenden Sie zur Lieferung die unterirdische Unterführung Pripyat 1. Der Lieferplan und die anschließende Versiegelung der Unterführung wurden an Abteilung 1 gesendet.";
		weight = 500;
		model = "DZ\gear\consumables\paper.p3d";
	};
	class X18_Quest_ManualForItem62 : FS_Document_3
	{
		scope = 2;
		displayName = "Handbuch zu Projekt-62";
		descriptionShort = "Das Handbuch beschreibt die Verwendung von Projekt-62. In den Anweisungen wird betont, dass keine Anpassungen für die Flugbahn oder den Wind des Geschosses vorgenommen werden müssen, da diese bei Entfernungen innerhalb der effektiven Reichweite der Waffe nicht wichtig sind. Diese Dokumente dürfen nicht in die Hände anderer fallen, da sie für USS-Analysten von großem Interesse wären.";
		weight = 500;
	};
	class X18_Quest_MercenaryNotebook : FS_PREDMET_Noutbuk
	{
		scope = 2;
		displayName = "Notebook eines Söldners";
		descriptionShort = "Das Notebook enthält eine Nachricht, die in einem Haufen Spam als wichtig markiert ist: 'Richten Sie ein Lager in der Nähe der Abfallverarbeitungsstation ein und jeder, der an diesem Job teilnehmen wird, wird sich Ihnen anschließen. Erwarten Sie nicht dass Black mit seinen Leuten auftaucht, diese sind auf einer anderen Mission bei Jupiter unterwegs. Die Armee hat alle Flüge in die Zone gestrichen, damit sollte es von dieser Seite keine Probleme geben. Wenn die Stalker einen Weg nach Pripyat finden, schicken wir einen Führer und warten dort auf die Leute des Kunden - sie zeigen uns, wo sich das Labor befindet. Jackal'";
		itemSize[] = { 5, 3 };
		weight = 3500;
		itemBehaviour = 2;
	};
	class X18_Quest_NotebookSheet : FS_Document_3
	{
		scope = 2;
		displayName = "Handbuch zu Projekt-62";
		descriptionShort = "Das Handbuch beschreibt die Verwendung von Projekt-62. In den Anweisungen wird betont, dass keine Anpassungen für die Flugbahn oder den Wind des Geschosses vorgenommen werden müssen, da diese bei Entfernungen innerhalb der effektiven Reichweite der Waffe nicht wichtig sind. Diese Dokumente dürfen nicht in die Hände anderer fallen, da sie für USS-Analysten von großem Interesse wären.";
		weight = 500;
	};
	class X18_Quest_OrderNo562 : FS_Document_3
	{
		scope = 2;
		displayName = "Handbuch zu Projekt-62";
		descriptionShort = "Streng geheim. Befehl Nr. 562 des HQ-Kommandanten, der für die Sicherheit von Objekt Nr. 1 verantwortlich ist, R. Yu. Didenko. Chemische Schutzeinheit Nr. 423: Umzug von Sektor B103 in Sektor A19, um Feldtests der chemischen Lösung Perin B3 unter Nahkampfbedingungen durchzuführen. Colonel P.P. Slavin, Befehlshaber der Einheit, ist für die Durchführung der Tests verantwortlich. Oberstleutnant K.S. Valov, stellvertretender Befehlshaber der Einheit, ist für Transport und Sicherheit verantwortlich.";
		weight = 500;
	};
	class X18_Quest_OrderOfTransfer : FS_Document_3
	{
		scope = 2;
		displayName = "Handbuch zu Projekt-62";
		descriptionShort = "Das Dokument bezieht sich auf den Transfer des Forschungsteams und aller Materialien in ein anderes Labor namens X7, das zur Erforschung von Fragen im Zusammenhang mit dem Einfluss der Noosphäre verwendet wird. Das Forschungsteam besteht aus: N.A. Lebedev, E.F. Kalancha und V.I. Suslow. Diese Dokumente dürfen nicht in die Hände anderer fallen, da sie für USS-Analysten von großem Interesse wären.";
		weight = 500;
	};
	class X18_Quest_PDA : Inventory_Base
	{
		scope = 2;
		displayName = "PDA (Beschädigt)";
		descriptionShort = "Dieses PDA sieht beschädigt aus aber vielleicht finde ich jemanden der mir helfen kann die Daten darauf zu retten.";
		weight = 500;
		model = "Noosphere\X18Items\QuestItems\Data\PDA.p3d";
	};
	class X18_Quest_RainbowEmitter : FS_Document_3
	{
		scope = 2;
		displayName = "Regenbogenemitter - technische Hauptmerkmale";
		descriptionShort = "Die Dokumente beschreiben die technischen Eigenschaften der Antenne und wie sie von ihren geplanten Werten abweichen. Auf der Rückseite befindet sich ein Hinweis, der darauf hinweist, dass diese Dokumente in Labor X10 erstellt wurden. Diese Dokumente dürfen nicht in die Hände anderer fallen, da sie für USS-Analysten von großem Interesse wären.";
		weight = 500;
	};
	class X18_Quest_ReportOnStudyOfSamples : FS_Document_3
	{
		scope = 2;
		displayName = "Bericht über die Untersuchung von Proben";
		descriptionShort = "Der Bericht beschreibt die Untersuchung von biologischen Proben, die aus Labor X18 gesendet wurden. Die Proben wurden Informationsfeldeffekten unterschiedlicher Intensität ausgesetzt. Der Bericht beschreibt akribisch die Mutation von Lebewesen nach Emissionseinwirkung. Diese Dokumente dürfen nicht in die Hände anderer fallen, da sie für USS-Analysten von großem Interesse wären.";
		weight = 500;
	};
	class X18_Quest_ResearchDocuments : FS_Document_3
	{
		scope = 2;
		displayName = "Forschungsdokumente";
		descriptionShort = "Die Dokumente beziehen sich auf eine der Nebenentdeckungen der Forschung, insbesondere auf die Entdeckung, dass Lebewesen in der Lage sind, gerichtete Psy-Emissionen zu erzeugen. Ein biologischer Feldemitter, im Wesentlichen ein Riesenhirn, wurde im Rahmen der im Labor X16 durchgeführten Forschung gezüchtet. Diese Dokumente dürfen nicht in die Hände anderer fallen, da sie für USS-Analysten von großem Interesse wären.";
		weight = 500;
	};
	class X18_Quest_SokolovsNote : Inventory_Base
	{
		scope = 2;
		displayName = "Sokolovs Notiz";
		descriptionShort = "Ein altes Blatt mit dem Wachdienstplan und den Nummern 1421 darunter. Eine Notiz, die mit einem Marker über der alten Schrift geschrieben war, lautete: 'Leutnant VI Sokolov. Nach dem Absturz des Hubschraubers ging ich zum Evakuierungspunkt B205. Zwei Tage lang wurden keine Evakuierungsversuche unternommen, und es ist riskant, an dieser Position zu bleiben. Ich habe mich daher entschieden. B205 zu verlassen und zum mobilen Labor der wissenschaftlichen Expedition zu gehen. Das Labor befindet sich nordöstlich des Evakuierungspunktes.'";
		weight = 500;
		model = "DZ\gear\consumables\paper.p3d";
	};
	class X18_Quest_UnderpassSchematics : FS_Document_3
	{
		scope = 2;
		displayName = "Unterführungs Bauplan";
		descriptionShort = "Pripyat 1-Unterführungsschemata, die zeigen, dass sich die Unterführung unter der Stadt Pripyat befindet. Das Dokument enthält mehrere Hinweise: Transportschloss Türen verschließen. Verwenden Sie Gas aus der chemischen Werkstatt, um die Unterführung abzudichten.";
		weight = 500;
	};
};