<?xml version='1.0'?>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
                version='1.0'
                xmlns="http://www.w3.org/TR/xhtml1/transitional"
                exclude-result-prefixes="#default">

<!-- The Makefile will substitute the real path to chunk.xsl here. -->
<xsl:import href="/export/home/daveho/linux/docbook/docbook-xsl-1.64.1/html/chunk.xsl"/>

<!-- This causes the stylesheet to put chapters in a single HTML file,
     rather than putting individual sections into seperate files. -->
<xsl:variable name="chunk.section.depth">0</xsl:variable>

<!-- Generate all HTML in this directory. -->
<xsl:variable name="base.dir"></xsl:variable>

<!-- Enumerate sections and subsections. -->
<xsl:variable name="section.autolabel">2</xsl:variable>

<!-- Name the HTML files based on the id of the document elements. -->
<xsl:variable name="use.id.as.filename">1</xsl:variable>

<!-- Use graphics in admonitions -->
<xsl:variable name="admon.graphics">1</xsl:variable>

<!-- Admonition graphics are in the "figures" directory. -->
<xsl:variable name="admon.graphics.path">figures/</xsl:variable>

<!-- Just put chapters, sect1s, and sect2s in the TOC. -->
<xsl:variable name="toc.section.depth">2</xsl:variable>

</xsl:stylesheet>
