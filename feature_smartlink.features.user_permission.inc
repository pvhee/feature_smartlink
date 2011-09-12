<?php

/**
 * Implementation of hook_user_default_permissions().
 */
function feature_smartlink_user_default_permissions() {
  $permissions = array();

  // Exported permission: administer smartlinks
  $permissions['administer smartlinks'] = array(
    'name' => 'administer smartlinks',
    'roles' => array(),
  );

  // Exported permission: apply to smartlinks
  $permissions['apply to smartlinks'] = array(
    'name' => 'apply to smartlinks',
    'roles' => array(),
  );

  // Exported permission: delete any smartlink content
  $permissions['delete any smartlink content'] = array(
    'name' => 'delete any smartlink content',
    'roles' => array(),
  );

  // Exported permission: delete own smartlink content
  $permissions['delete own smartlink content'] = array(
    'name' => 'delete own smartlink content',
    'roles' => array(),
  );

  // Exported permission: edit any smartlink content
  $permissions['edit any smartlink content'] = array(
    'name' => 'edit any smartlink content',
    'roles' => array(),
  );

  // Exported permission: edit field_smartlink_fields
  $permissions['edit field_smartlink_fields'] = array(
    'name' => 'edit field_smartlink_fields',
    'roles' => array(),
  );

  // Exported permission: edit own smartlink content
  $permissions['edit own smartlink content'] = array(
    'name' => 'edit own smartlink content',
    'roles' => array(),
  );

  // Exported permission: view field_smartlink_fields
  $permissions['view field_smartlink_fields'] = array(
    'name' => 'view field_smartlink_fields',
    'roles' => array(),
  );

  return $permissions;
}
