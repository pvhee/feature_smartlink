<?php

/**
 * Implementation of hook_node_info().
 */
function feature_smartlink_node_info() {
  $items = array(
    'smartlink' => array(
      'name' => t('Smartlink'),
      'module' => 'features',
      'description' => t('A smartlink for creating targeted invites.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('Body'),
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implementation of hook_views_api().
 */
function feature_smartlink_views_api() {
  return array(
    'api' => '2',
  );
}
